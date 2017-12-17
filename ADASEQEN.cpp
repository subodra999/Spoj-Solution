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
#define test() int t; scanf("%d",&t); while(t--)


using namespace std;
typedef long long int ll;
const int N =(int) 1e3+4;


int main()
{
	int n,m;
	cin >> n >> m;
	ll cost[26];
	lpi(i,0,25)
		cin >> cost[i];
	string s1,s2;
	cin >> s1 >> s2;
	s1 = " "+s1;
	s2 = " "+s2;
	ll dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	lpi(i,1,n)
	{
		lpi(j,1,m)
		{
			if(s1[i] == s2[j])
			{
				dp[i][j] = dp[i-1][j-1]+cost[s1[i]-'a'];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout << dp[n][m];
	return 0;
}