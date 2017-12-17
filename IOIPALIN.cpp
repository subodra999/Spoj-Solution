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

int n,ans,dp[5005][5005];
string s;

int recur(int l,int r)
{
	if(dp[l][r] != -1)
		return dp[l][r];
	if(l == r)
		return 0;
	if(l > r)
		return 0;
	if(s[l] == s[r])
		return dp[l][r] = recur(l+1,r-1);
	return dp[l][r] = min(recur(l,r-1) , recur(l+1,r))+1;
}
int main()
{
	cin >> n;
	cin >> s;
	memset(dp,-1,sizeof(dp));
	ans = recur(0,n-1);
	cout << ans;
	return 0;
}