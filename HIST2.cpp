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
struct node{
	int val,per;
};
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0)
			return 0;
		int ar[n];
		lpi(i,0,n-1)
			cin >> ar[i];
		node dp[1<<n][n];
		memset(dp,0,sizeof(dp));
		lpi(i,0,n-1)
		{
			dp[1<<i][i].val = ar[i]*2+2;
			dp[1<<i][i].per = 1;
		}
		int limit = 1<<n;
		lpi(mask,0,limit-1)
		{
			lpi(i,0,n-1)
			{
				if(mask&(1<<i))    //ith bit is set
				{
					lpi(j,0,n-1)
					{
						if(j!=i && mask&(1<<j))    //jth bit is set
						{
							if(ar[j] < ar[i])
							{
								int next = dp[mask^(1<<i)][j].val+2+2*(ar[i]-ar[j]);
								int peru = dp[mask^(1<<i)][j].per;
								if(dp[mask][i].val < next)
									dp[mask][i].val = next, dp[mask][i].per = peru;
								else if(dp[mask][i].val == next)
									dp[mask][i].per += peru;
							}
							else
							{
								int next = dp[mask^(1<<i)][j].val+2;
								int peru = dp[mask^(1<<i)][j].per;
								if(dp[mask][i].val < next)
									dp[mask][i].val = next, dp[mask][i].per = peru;
								else if(dp[mask][i].val == next)
									dp[mask][i].per += peru;
							}
						}
					}
				}
			}
		}
		int ans = 0,aper=0;
		lpi(i,0,n-1)
		{
			if(ans < dp[limit-1][i].val)
			{

				ans = dp[limit-1][i].val ;
				aper = dp[limit-1][i].per ;
			}
			else if(ans == dp[limit-1][i].val)
			{
				aper += dp[limit-1][i].per;
			}
		}
		cout << ans << " " << aper << endl;
	}
	return 0;
}