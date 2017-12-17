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
const int N =(int) 5e2+4;

ll n,k,t;
ll h[N];
ll dp[N][N];
ll recur(ll next,ll cnt)
{
	if(cnt == 0 || next == n)
		return 0;
	if(dp[next][cnt] != -1)
		return dp[next][cnt];
	ll curr = recur(next+1,cnt);
	ll hg = inf;
	for(ll i=next+1;i<=n;i++)
	{
		hg = min(hg,h[i]);
		if(i-next <= t)
			curr = max(curr, hg*(i-next)+recur(i,cnt-1));
		else
			break;
	}
	return dp[next][cnt] = curr;
}

int main()
{
	cin >> n >> k >> t;
	memset(dp,-1,sizeof(dp));
	lpi(i,1,n)
		cin >> h[i];
	ll ans = recur(0,k);
	cout << ans;
	return 0;
}