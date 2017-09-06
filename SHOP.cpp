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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	while(1)
	{
		int n,m,str,des;
		char c;
		cin >> m >> n;
		if(n==0)
			return 0;
		int g[n][m];
		lpi(i,0,n-1)
		{
			lpi(j,0,m-1)
			{
				cin >> c;
				if(c == 'S')
				{
					g[i][j] = 0;
					str = i*m+j;
				}
				else if(c == 'D')
				{
					g[i][j] = 0;
					des = i*m+j;
				}
				else if(c == 'X')
				{
					g[i][j] = -1;
				}
				else
				{
					g[i][j] = c-'0';
				}
			}
		}
		int ar[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
		vector<pii > adj[n*m];
		lpi(i,0,n-1)
		{
			lpi(j,0,m-1)
			{
				int p = i*m+j;
				if(p == des)
					continue;
				lpi(k,0,3)
				{
					int x=i+ar[k][0] , y=j+ar[k][1];
					if(x>=0 && x<n && y>=0 && y<m && g[x][y]!=-1)
					{
						adj[p].pb(mp(x*m+y, g[x][y]));            //idx, time
					}
				}
			}
		}

		vii dp(n*m,100000);
		queue<pii > q;
		q.push(mp(0,str));
		int ans = 100000;
		while(!q.empty())
		{
			pii p = q.front();
			q.pop();
			if(p.ss == des)
			{
				ans = min(p.ff,ans);
			}
			tr(adj[p.ss],it)
			{
				if((*it).ff != p.ss && dp[(*it).ff]>(p.ff+(*it).ss))
				{
					dp[(*it).ff] = (*it).ss+p.ff;
					q.push(mp((*it).ss+p.ff,(*it).ff));
				}
			}
		}	
		cout << ans << endl;	
	}
	
	return 0;
}