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

#define speed ios::sync_with_stdio(false)
#define mod 1000000007
#define nax 10005
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
typedef long double ld;

ll fast_exp(ll a,ll b)
{
	if(a==0)
		return 0;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(b%2==0)
	{
		return fast_exp(((a%mod)*(a%mod))%mod,b/2)%mod;
	}
	return ((a%mod)*fast_exp(((a%mod)*(a%mod))%mod,(b-1)/2))%mod;
}

int main()
{
	while(1)
	{
		int n,m,sx,sy;
		cin >> m >> n;
		if(m==0 && n==0)
			return 0;
		char g[n][m];
		vector<pii > dirty;
		lpi(i,0,n-1)
		{
			lpi(j,0,m-1)
			{
				cin >> g[i][j];
				if(g[i][j] == '*')
				{
					dirty.pb(mp(i,j));
				}
				else if(g[i][j] == 'o')
				{
					sx = i, sy = j;
				}
			}
		}
		int temp[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
		int len = dirty.size();
		int lev[n][m][len];
		memset(lev,nax,sizeof(lev));
		bool vis[n][m];
		lpi(i,0,len-1)
		{
			memset(vis,true,sizeof(vis));
			queue<pii > q;
			q.push(mp(dirty[i].ff,dirty[i].ss));
			lev[dirty[i].ff][dirty[i].ss][i] = 0;
			vis[dirty[i].ff][dirty[i].ss] = false;
			while(!q.empty())
			{
				pii p = q.front();
				q.pop();
				lpi(k,0,3)
				{
					int x = p.ff+temp[k][0], y = p.ss+temp[k][1];
					if(x>=0 && x<n && y>=0 && y<m)
					{
						if(vis[x][y] && g[x][y] != 'x')
						{
							q.push(mp(x,y));
							vis[x][y] = false;
							lev[x][y][i] = lev[p.ff][p.ss][i]+1;
						}
					}
				}
			}
		}
		int levR[n][m];
		memset(levR,nax,sizeof(levR));
		memset(vis,true,sizeof(vis));
		queue<pii > q;
		q.push(mp(sx,sy));
		levR[sx][sy] = 0;
		vis[sx][sy] = false;
		while(!q.empty())
		{
			pii p = q.front();
			q.pop();
			lpi(k,0,3)
			{
				int x = p.ff+temp[k][0], y = p.ss+temp[k][1];
				if(x>=0 && x<n && y>=0 && y<m)
				{
					if(vis[x][y] && g[x][y] != 'x')
					{
						q.push(mp(x,y));
						vis[x][y] = false;
						levR[x][y] = levR[p.ff][p.ss]+1;
					}
				}
			}
		}
		int limit = 1<<len;
		int dp[len][limit];
		memset(dp,nax,sizeof(dp));
		for(int i=0;i<len;i++)
		{
			dp[i][1<<i] = levR[dirty[i].ff][dirty[i].ss];
			//cout << dp[i][1<<i] << endl;
		}
	/*	lpi(i,0,n-1)
		{
			lpi(j,0,m-1)
			{
				cout << levR[i][j]<<" ";
			}
			cout << endl;
		}*/
		lpi(mask,2,limit-1)
		{
			lpi(i,0,len-1)
			{
				if(mask&(1<<i))         //ith bit is set
				{
					lpi(j,0,len-1)
					{
						if(i != j)
						{
							if(mask&(1<<j))   //jth bit is set
							{
								dp[i][mask] = min(dp[i][mask], dp[j][mask^(1<<i)]+lev[dirty[i].ff][dirty[i].ss][j]);
							}
						}
					}
				}
			}
		}
		int ans = nax;
		lpi(i,0,len-1)
		{
			ans  =  min(ans , dp[i][limit-1]);
		}
		if(ans == nax)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
}

