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

int n,k;
int ar[1001];
bool dp[1001][1001];
int ans = 0; 

void recur(int str,int sum)
{
	if(sum > k)
		return ;
	if(sum > ans)
		ans = sum;
	dp[str][sum] = false;
	if(str+1<n && dp[str+1][sum])
		recur(str+1, sum);
	sum += ar[str];
	if(sum > k)
		return ;
	if(sum > ans)
		ans = sum;
	if(str+2<n && dp[str+2][sum])
		recur(str+2,sum);
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int tc;
	cin >> tc;
	lpi(t,1,tc)
	{
		cin >> n >> k;
		lpi(i,0,n-1)
			cin >> ar[i];
		memset(dp,true,sizeof(dp));
		ans = 0;
		recur(0,0);
		cout <<"Scenario #"<<t<<": "<<ans << endl;
	}

	return 0;
}