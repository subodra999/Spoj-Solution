#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<cstring>

#define ll long long int
#define lb long double
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define in insert
#define ff first
#define ss second
#define lpi(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

const int N = (int)1e5+5;

ll n, t[4*N], ar[N];

void build(ll l,ll r,ll node)
{
	if(l == r)
	{
		t[node] = l;
		return;
	}
	ll mid = (l+r)/2;
	build(l,mid,2*node+1);
	build(mid+1,r,2*node+2);
	t[node] = ar[t[2*node+1]] < ar[t[2*node+2]] ? t[2*node+1] : t[2*node+2];
}

ll find_idx(ll l,ll r,ll sl,ll sr,ll node)
{
	if(l > sr || r < sl)
		return -1;
	if(sl<=l && r<=sr)
		return t[node];
	ll mid = (l+r)/2;
	ll t1 = find_idx(l,mid,sl,sr,2*node+1);
	ll t2 = find_idx(mid+1,r,sl,sr,2*node+2);
	if(t1 == -1)
		return t2;
	if(t2 == -1)
		return t1;
	return (ar[t1] < ar[t2] ? t1 : t2);
}

ll query(ll l,ll r)
{
	if(l>r)
		return -1;
	ll min_idx = find_idx(0,n-1,l,r,0);
	ll t1 = query(l,min_idx-1);
	ll t2 = query(min_idx+1,r);
	ll temp = max(t1,t2);
	return max(temp, ar[min_idx]*(r-l+1));
}

int main()
{
	while(1)
	{
		cin >> n;
		if(n == 0)
			return 0;
		lpi(i,0,n-1)
			cin >> ar[i];
		build(0,n-1,0);
		cout << query(0,n-1) << endl;
	}
	return 0;
}