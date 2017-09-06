#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

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

ll set_one(ll a)
{
	ll ans=0;
	while(a)
	{
		a = a&(a-1);
		ans++;
	}
	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	cin >> t;
	while(t--)
	{
		int n=11;
		int ar[n][n];
		lpi(i,0,n-1)
		{
			lpi(j,0,n-1)
				cin >> ar[i][j];
		}
		ll limit = 1LL<<n;
		ll dp[limit];
		lpl(i,0,limit-1)
			dp[i] = -nax;
		dp[0] = 0;
		lpl(mask,0,limit-1)
		{
			ll cnt = set_one(mask);
			lpi(i,0,n-1)
			{
				if(!(mask&(1LL<<i)))   //ith bit unset
				{
					if(ar[cnt][i] != 0)
						dp[mask|(1LL<<i)] = max(dp[mask|(1LL<<i)], dp[mask]+ar[cnt][i]);
				}
			}
		}
		cout << dp[limit-1] << endl;
	}
	return 0;
}