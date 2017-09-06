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

vii adj[100005];
int dp[100005][2];

int recur(int p,int taken,int v)
{
	if(dp[v][taken] != -1)
		return dp[v][taken];
	int ans = 0;
	tr(adj[v], it)
	{
		if(*it != p)
		{
			if(taken)
				ans += min(recur(v,1,*it), recur(v,0,*it));
			else
				ans += recur(v,1,*it);
		}
	}
	ans += taken;
	return dp[v][taken] = ans;
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int n,x,y;
	cin >> n;
	lpi(i,2,n)
	{
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	memset(dp,-1,sizeof(dp));
	int ans = min(recur(-1,0,1), recur(-1,1,1));
	cout << ans;
	return 0;
}