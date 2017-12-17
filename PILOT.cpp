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

int n;
node ar[10005];
ll ans=0;
ll dp[10005][5005];

ll recur(int idx,int captain,int assistant)
{
	if(dp[idx][assistant] != -1)
		return dp[idx][assistant];
	if(idx == n)
	{
		return 0;
	}
	if(assistant == n/2)
	{
		return dp[idx][assistant] = (ar[idx].cap+recur(idx+1,captain+1,assistant));
	}
	else if(assistant == captain)
	{
		return dp[idx][assistant] = (ar[idx].ast+recur(idx+1,captain,assistant+1));
	}
	else
	{
		return dp[idx][assistant] = min(ar[idx].ast+recur(idx+1,captain,assistant+1), ar[idx].cap+recur(idx+1,captain+1,assistant));
	}
}

int main()
{
	cin >> n;
	lpi(i,0,n-1)
		cin >> ar[i].cap >> ar[i].ast;
	memset(dp,-1,sizeof(dp));
	dp[0][0] = ar[0].ast+recur(1,0,1);
	cout << dp[0][0];
	return 0;
}