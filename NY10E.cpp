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
int n;
ll dp[65][10];

ll recur(int str,int l)
{
	if(l == n)
		return 1;
	if(dp[l][str] != -1)
		return dp[l][str];
	ll ans=0;
	lpi(i,str,9)
	{
		ans += recur(i,l+1);
	}
	return dp[l][str] = ans;
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	cin >> t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		int tc;
		ll ans=0;
		cin >> tc >> n;
		lpi(i,0,9)
		{
			ans += recur(i,1);
		}
		cout << tc << " " << ans << endl;
	}
	return 0;
}