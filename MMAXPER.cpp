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
	int l,b;
};
int main()
{
	int n;
	cin >> n;
	node ar[n];
	lpi(i,0,n-1)
	{
		cin >> ar[i].l >> ar[i].b;
	}
	vector<vii > dp(n, vector<int>(2,0));
	dp[0][0] = ar[0].l , dp[0][1] = ar[0].b;
	lpi(i,1,n-1)
	{
		dp[i][0] = max(dp[i-1][0]+abs(ar[i].b-ar[i-1].b), dp[i-1][1]+abs(ar[i-1].l-ar[i].b))+ar[i].l;
		dp[i][1] = max(dp[i-1][0]+abs(ar[i].l-ar[i-1].b), dp[i-1][1]+abs(ar[i-1].l-ar[i].l))+ar[i].b;
	}
	cout << max(dp[n-1][0], dp[n-1][1]) << endl;
	return 0;
}