#include<bits/stdc++.h>
using namespace std;
string s;
struct bracket
{
	int left,right;
}tree[1000005];

void build(int l,int r,int node)
{
	if(l == r)
	{
		if(s[l] == '(')
		{
			tree[node].left = 1;
			tree[node].right = 0;
		}
		else
		{
			tree[node].left = 0;
			tree[node].right = 1;	
		}
	}
	else
	{
		int mid = (l+r)/2;
		build(l , mid , 2*node);
		build(mid+1 , r , 2*node+1);
		int m = min(tree[2*node].left,tree[2*node+1].right);
		tree[node].left = tree[2*node].left + tree[2*node+1].left - m;
		tree[node].right = tree[2*node].right + tree[2*node+1].right - m;
	}
}
void update(int l ,int r,int n,int node)
{
	if(n < l || n > r)
		return;
	if(l == r && l == n)
	{
		if(s[n] == '(')
		{
			s[n] = ')';
			tree[node].left = 0;
			tree[node].right = 1;
 		}
 		else
 		{
 			s[n] = '(';
			tree[node].left = 1;
			tree[node].right = 0;
 		}
	}
	else
	{
	    int mid = (l+r)/2;
	    update(l , mid , n , 2*node);
	    update(mid+1 , r , n , 2*node+1);
	    int m = min(tree[2*node].left,tree[2*node+1].right);
	    tree[node].left = tree[2*node].left + tree[2*node+1].left - m;
	    tree[node].right = tree[2*node].right + tree[2*node+1].right - m;

	    
	}
}
int main()
{
	int t=1;
	while(t<11)
	{
		printf("Test %d:\n",t);
		t++;
		int l;
		scanf("%d",&l);
		cin >> s;
		s = " "+s;
		build(1,l,1);
		int q,c;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&c);
			if(c == 0)
			{
				if(tree[1].left == 0 && tree[1].right == 0)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
			{
				update(1,l,c,1);
			}
		}
	}
}