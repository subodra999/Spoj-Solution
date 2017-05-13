#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n,q;
	cin >> n >> q;
	ll x,y;
	ll ar[n+2];
	memset(ar,0,sizeof(ar));
	for(ll i=0 ; i<q ; ++i)
	{
		cin >> x >> y;
		ar[x]+=1;
		ar[y+1]-=1;
	}
	for(ll i=2 ; i<=n ; ++i)
	{
		ar[i]+=ar[i-1];
	}
	sort(ar+1,ar+n+1);
	/*for(ll i=1;i<=n;i++){
		cout << ar[i] << " ";
	}*/
	cout << ar[(ll)ceil(n/2.0)] << endl;
}