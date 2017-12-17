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
#define speed ios::sync_with_stdio(false)

using namespace std;
typedef long long int ll;

struct node
{
	ll cap, ast;
};



int main()
{
	int n;
	while(cin >> n)
	{
		ll ar[n];
		ll dp[n][n], dp_t[n][n];
		memset(dp,0,sizeof(dp));
		memset(dp_t,0,sizeof(dp_t));
		lpi(i,0,n-1)
		{
			cin >> ar[i];
			dp_t[i][i] = ar[i];
		}
		lpi(i,0,n-2)
		{
			dp_t[i][i+1] = (ar[i]+ar[i+1])%100;
			dp[i][i+1] = (ar[i]*ar[i+1]);
		}
		lpi(i,2,n)
		{
			lpi(j,0,n-i)   //start
			{
				ll temp = inf, smoke;
				int lim = j+i-1;
				lpi(k,j,lim-1)
				{
					ll x = dp_t[j][k]*dp_t[k+1][lim] + dp[j][k] + dp[k+1][lim];
					if(x < temp)
					{
						temp = x;
						smoke = (dp_t[j][k]+dp_t[k+1][lim])%100;
					}
				}
				dp[j][lim] = temp;
				dp_t[j][lim] = smoke;
			}
		}
		cout << dp[0][n-1] << endl;
	}
	return 0;
}