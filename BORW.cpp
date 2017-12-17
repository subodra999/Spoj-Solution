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

int n;
int ar[205];
int dp[205][205][205];

int recur(int b_idx,int w_idx,int idx)
{
	if(dp[idx][b_idx][w_idx] != -1)
		return dp[idx][b_idx][w_idx];
	if(idx > n)
		return 0;
	if(ar[idx] < ar[w_idx] && ar[idx] > ar[b_idx])
		return dp[idx][b_idx][w_idx] = min(1+recur(b_idx,w_idx,idx+1), min(recur(idx,w_idx,idx+1), recur(b_idx,idx,idx+1)));
	if(ar[idx] < ar[w_idx])
		return dp[idx][b_idx][w_idx] = min(1+recur(b_idx,w_idx,idx+1), recur(b_idx,idx,idx+1));
	if(ar[idx] > ar[b_idx])
		return dp[idx][b_idx][w_idx] = min(1+recur(b_idx,w_idx,idx+1), recur(idx,w_idx,idx+1));
	else
		return dp[idx][b_idx][w_idx] = (1+recur(b_idx,w_idx,idx+1));
}

int main()
{
	while(cin >> n)
	{
		if(n == -1)
			return 0;
		lpi(i,1,n)
			cin >> ar[i];
		memset(dp,-1,sizeof(dp));
		ar[0] = 0, ar[n+1] = 1000005;
		int ans = min(1+recur(0,n+1,2), min(recur(1,n+1,2), recur(0,1,2)));
		cout << ans << endl;
	}
	return 0;
}