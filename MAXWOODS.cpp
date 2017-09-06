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

int dp[205][205][2]; //0->left 1->right
int ar[205][205];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		char c;
		cin >> n >> m;
		lpi(i,1,n)
		{
			lpi(j,1,m)
			{
				cin >> c;
				if(c == 'T')
					ar[i][j] = 2;
				else if(c == '0')
					ar[i][j] = 1;
				else
					ar[i][j] = 0;
			}
		}	
		memset(dp,0,sizeof(dp));
		lpir(i,n,1)
		{
			lpi(j,1,m)
			{
				if(ar[i][j])
				{
					dp[i][j][0] = max(dp[i][j-1][0] , dp[i+1][j][1]) + ar[i][j] - 1;
				}
			}
			lpir(j,m,1)
			{
				if(ar[i][j])
				{
					dp[i][j][1] = max(dp[i][j+1][1] , dp[i+1][j][0]) + ar[i][j] - 1;
				}
			}
		}
		cout << dp[1][1][1] << endl;
	}
	return 0;
}