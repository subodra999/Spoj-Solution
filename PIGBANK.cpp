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
const int N =(int) 1e4+4;

int dp[N];

int main()
{
	test()
	{
		memset(dp,-1,sizeof(dp));
		int n,e,f;
		scanf("%d %d",&e,&f);
		f -= e;
		scanf("%d",&n);
		int p[n],w[n];
		lpi(i,0,n-1)
		{
			scanf("%d %d",&p[i],&w[i]);
			//cin >> p[i] >> w[i];
		}
		dp[0] = 0;
		lpi(i,1,f)
		{
			lpi(j,0,n-1)
			{
				if(i>=w[j] && dp[i-w[j]]!=-1 && (dp[i]==-1 || p[j]+dp[i-w[j]] < dp[i]))
					dp[i] = p[j] + dp[i-w[j]];
			}
		}
		if(dp[f]==-1) 
			printf("This is impossible.\n");
		
		else 
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f]);
		

	}
	return 0;
}