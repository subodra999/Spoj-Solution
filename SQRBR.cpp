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
#define test() int t; cin >> t; while(t--)

using namespace std;
typedef long long int ll;

int n,k,a;
bool open[100];
int dp[100][100][100];

int recur(int op, int cl, int idx)
{
	if(dp[op][cl][idx] != -1)
		return dp[op][cl][idx];
	if(idx == 2*n)
	{
		if(open[idx])
			return dp[op][cl][idx] = 0;
		if(cl+1 == op)
			return dp[op][cl][idx] = 1;
		else
			return dp[op][cl][idx] = 0;
	}
	if(open[idx])
	{
		return dp[op][cl][idx] = recur(op+1,cl,idx+1);
	}
	if(op == cl)
		return dp[op][cl][idx] = recur(op+1,cl,idx+1);
	else if(op > cl && op < n)
		return dp[op][cl][idx] = recur(op+1,cl,idx+1)+recur(op,cl+1,idx+1);
	else
		return dp[op][cl][idx] = recur(op,cl+1,idx+1);
}

int main()
{
	test()
	{
		memset(open, false, sizeof(open));
		memset(dp, -1, sizeof(dp));
		cin >> n >> k;
		lpi(i,1,k)
		{
			cin >> a;
			open[a] = true;
		}
		int ans = recur(1,0,2);
		cout << ans << endl;
	}
	return 0;
}