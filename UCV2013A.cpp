#include<bits/stdc++.h>

#define mod 1000000007
#define nax 1000005
#define inf 100000000000000000LL
#define pb push_back
#define mp make_pair
#define in insert
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>
#define vii vector<int>
#define sii set<int>
#define vb vector<bool>
#define sll set<long long int>
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mis map<int,string>
#define all(n) n.begin(),n.end()
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define lpi(i,a,b) for(int i=a;i<=b;i++)
#define lpir(i,a,b) for(int i=a;i>=b;i--)
#define lpl(i,a,b) for(ll i=a;i<=b;++i)
#define lplr(i,a,b) for(ll i=a;i>=b;--i)
#define lpv(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)

using namespace std;
typedef long long int ll;

ll power(ll x,ll y)
{
	if (y == 0)
        return 1;
    ll p = power(x, y/2) % mod;
    p = (p * p) % mod;
 
    return (y%2 == 0)? p : (x * p) % mod;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	ll n,l;
	
	while(1)
	{
		if(n==0 && l==0)
			return 0;
		cin >> n >> l;
		ll ans=0;
		lpl(i,1,l)
		{
			ans = (ans+power(n,i))%mod;
		}
		cout << ans << endl;
	}
	return 0;
}
//65535

