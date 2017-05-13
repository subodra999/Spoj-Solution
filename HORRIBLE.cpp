#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll tree[4000009],lazy[4000009];
void update(ll l,ll r,ll lo,ll hi,ll n,ll node)
{
	if(lazy[node] != 0)
	{
		tree[node] += (r-l+1)*lazy[node];
		if(l != r)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}	
		lazy[node] = 0;
	}
	if(l>hi || r<lo)
		return;
	ll mid = l+(r-l)/2;
	if(l >= lo && r <= hi)
	{
		tree[node] += (r-l+1)*n;
		if(l != r)
		{
			lazy[2*node] += n;
			lazy[2*node+1] += n;
		}
		return;
	}
	else
	{
		update(l,mid,lo,hi,n,2*node);
		update(mid+1,r,lo,hi,n,2*node+1);
		tree[node] = tree[2*node]+tree[2*node+1];
	}

}
ll query(ll l ,ll r,ll lo,ll hi,ll node)
{
	if(lazy[node] != 0)
	{
		tree[node] += (r-l+1)*lazy[node];
		if(l != r)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}	
		lazy[node] = 0;
	}
	if(l>hi || r<lo)
		return 0;
	ll mid = l+(r-l)/2;
	if(l >= lo && r <= hi)
	{
		return tree[node];
	}
	else
	{
		ll a = query(l,mid,lo,hi,2*node);
		ll b = query(mid+1,r,lo,hi,2*node+1);
		return (a+b);
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
		ll n,q,x,y,num,check;
		cin >> n >> q;
		while(q--)
		{
			cin >> check;
			if(check == 0)
			{
				cin >> x >> y >> num;
				update(1,n,x,y,num,1);
			}
			else
			{
				cin >> x >> y;
				ll ans =  query(1,n,x,y,1);
				cout << ans << endl;
			}
		}
	}
}