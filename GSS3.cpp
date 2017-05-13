#include<bits/stdc++.h>
#define vll vector<long int>
using namespace std;
typedef long int ll;
struct seg{
	ll sum;
	ll maxPre;
	ll maxSuf;
	ll ans;
};

vll ar(100005);
vector<seg> tree(200005);

void build(ll l , ll r , ll node)
{
	if(l == r)
	{
		tree[node].sum = tree[node].maxPre = tree[node].maxSuf = tree[node].ans = ar[l];
	}	
	else
	{
		ll mid = (l+r)/2;
		build(l,mid,2*node);
		build(mid+1,r,2*node+1);
		ll right = 2*node+1;
		ll left = 2*node;
		tree[node].sum = tree[left].sum + tree[right].sum;
		tree[node].maxPre = max(tree[left].maxPre , tree[left].sum+tree[right].maxPre);
		tree[node].maxSuf = max(tree[left].maxSuf+tree[right].sum , tree[right].maxSuf);
		tree[node].ans = max(tree[left].ans , max(tree[right].ans , max(tree[node].maxSuf , max(tree[node].maxPre , tree[right].maxPre+tree[left].maxSuf))));
 	}
}
struct seg query(ll l , ll r , ll lo , ll hi , ll node)
{
	if(l >= lo && r <= hi)
	{
		return tree[node];
	}
	else
	{
		ll mid = (l+r)/2;
		struct seg a , left , right;
		if(mid < lo)
		{
			return query(mid+1,r,lo,hi,2*node+1);
		}
		else if(hi <= mid)
		{
		    return query(l,mid,lo,hi,2*node);
		}
		else
		{
			left = query(l,mid,lo,hi,2*node);
			right = query(mid+1,r,lo,hi,2*node+1);
			a.sum = left.sum + right.sum;
			a.maxPre = max(left.maxPre , left.sum+right.maxPre);
			a.maxSuf = max(right.maxSuf , right.sum+left.maxSuf);
			a.ans = max(left.ans , max(right.ans , max(a.maxSuf , max(a.maxPre , right.maxPre+left.maxSuf))));
			return a;
		}

	}
}
void update(ll l,ll r,ll idx,ll n,ll node)
{
    if(idx > r || idx < l)
    {
        return;
    }
    if(l == r)
    {
        ar[idx] = n;
        tree[node].sum = tree[node].maxPre = tree[node].maxSuf = tree[node].ans = ar[idx] ;
    }
    else
    {
        ll mid = (l+r)/2;
        ll right = 2*node+1;
		ll left = 2*node;
		update(l,mid,idx,n,2*node);
		update(mid+1,r,idx,n,2*node+1);
		tree[node].sum = tree[left].sum + tree[right].sum;
		tree[node].maxPre = max(tree[left].maxPre , tree[left].sum+tree[right].maxPre);
		tree[node].maxSuf = max(tree[left].maxSuf+tree[right].sum , tree[right].maxSuf);
		tree[node].ans = max(tree[left].ans , max(tree[right].ans , max(tree[node].maxSuf , max(tree[node].maxPre , tree[right].maxPre+tree[left].maxSuf))));
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); 

	ll n,l,r,c;
	scanf("%ld",&n);
	for(ll i=1; i<=n; i++)
		scanf("%ld",&ar[i]);

	build(1,n,1);
	ll q;
	scanf("%ld",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%ld %ld %ld",&c,&l,&r);
		if(c == 1)
		{
		    struct seg a = query(1,n,l,r,1);
	    	printf("%ld\n",a.ans);
		}
		else if(c == 0)
		{
		    update(1,n,l,r,1);
		}
	}
	return 0;
}
