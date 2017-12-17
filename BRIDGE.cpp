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

bool cmp(pii a,pii b)
{
	if(a.ff == b.ff)
		return a.ss < b.ss;
	return a.ff < b.ff;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<pii > v(n);
		lpi(i,0,n-1)
		{
			cin >> v[i].ff ;
		}
		lpi(i,0,n-1)
		{
			cin >> v[i].ss;
		}
		sort(all(v),cmp);
		vector<int> dp(n,1);
		int ans = 1;
		lpi(i,1,n-1)
		{
			lpi(j,0,i-1)
			{
				if(v[i].ss >= v[j].ss)
				{
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
			ans = max(ans, dp[i]);
			//cout << dp[i] << " ";
		}
		cout << ans << endl << endl;
	}
	return 0;
}