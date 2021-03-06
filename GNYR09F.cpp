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

int n,k,tc;
int dp[105][105][105];

int recur(int one,int cnt,int idx)
{
	if(dp[one][cnt][idx] != -1)
		return dp[one][cnt][idx];
	if(idx > n)
	{
		if(cnt == k)
			return 1;
		else
			return 0;
	}
	int a;
	if(one+1 == idx)
		a = recur(idx,cnt+1,idx+1);
	else
		a = recur(idx,cnt,idx+1);
	return dp[one][cnt][idx] = a+recur(one,cnt,idx+1);
}

int main()
{
	test()
	{
		cin >> tc >> n >> k;
		memset(dp,-1,sizeof(dp));
		int ans = recur(1,0,2)+recur(0,0,2);
		cout << tc << " " << ans << endl;
	}
	return 0;
}