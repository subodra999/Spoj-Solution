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
#define ld long double
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define in insert
#define ff first
#define ss second
#define lpi(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

const int N = (int)1e5+5;

ll ar[N], t[4*N][2];

void build(ll l,ll r,ll node)
{
	if(l == r)
	{
		t[node][0] = ar[l],  t[node][1] = 0;
		return;
	}
	ll mid = (l+r)/2;
	build(l,mid,2*node+1);
	build(mid+1,r,2*node+2);
	t[node][0] = max(t[2*node+1][0] , t[2*node+2][0]);
	t[node][1] = min(max(t[2*node+1][0],t[2*node+2][1]), max(t[2*node+2][0],t[2*node+1][1]));
}

void update(ll l,ll r,ll idx,ll val,ll node)
{
	if(l>idx || r<idx)
		return;
	if(l == r && l == idx)
	{
		ar[l] = val;
		t[node][0] = ar[l],  t[node][1] = 0;
		return;
	}
	ll mid = (l+r)/2;
	update(l,mid,idx,val,2*node+1);
	update(mid+1,r,idx,val,2*node+2);
	t[node][0] = max(t[2*node+1][0] , t[2*node+2][0]);
	t[node][1] = min(max(t[2*node+1][0],t[2*node+2][1]), max(t[2*node+2][0],t[2*node+1][1]));
}

pair<ll,ll> query(ll l,ll r,ll sl,ll sr,ll node)
{
	if(l>sr || r<sl)
		return mp(0,0);
	if(sl<=l && r<=sr)
		return mp(t[node][0],t[node][1]);
	ll mid = (l+r)/2;
	pair<ll,ll> t1,t2,temp;
	t1 = query(l,mid,sl,sr,2*node+1);
	t2 = query(mid+1,r,sl,sr,2*node+2);
	temp.ff = max(t1.ff , t2.ff);
	temp.ss = min(max(t1.ff,t2.ss), max(t1.ss,t2.ff));
	return temp;
}

int main()
{
	ll n,q,l,r;
	char c;

	cin >> n;
	
	lpi(i,0,n-1)
		cin >> ar[i];
	
	build(0,n-1,0);

	cin >> q;
	
	while(q--)
	{
		cin >> c >> l >> r;
		if(c == 'U')
		{
			l--;
			update(0,n-1,l,r,0);
		}
		else
		{
			l--, r--;
			pair<ll,ll> ans = query(0,n-1,l,r,0);
			cout << (ans.ff+ans.ss) << endl;
		}
	}
	return 0;
}