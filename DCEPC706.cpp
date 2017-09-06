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

int n,m;
char ar[205][205];
bool vis[205][205][3];
int lev[205][205][3];

void bfs(int px,int py,int idx)
{
	int temp[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	queue<pii > q;
	q.push(mp(px,py));
	lev[px][py][idx] = 0;
	vis[px][py][idx] = false;
	while(!q.empty())
	{
		pii p = q.front();
		q.pop();
		lpi(i,0,3)
		{
			int x=p.ff+temp[i][0], y=p.ss+temp[i][1];
			if(x>=0 && x<=n+1 && y>=0 && y<=m+1 && vis[x][y][idx] && ar[x][y]!='#')
			{
				q.push(mp(x,y));
				lev[x][y][idx] = lev[p.ff][p.ss][idx]+1;
				vis[x][y][idx] = false;
			}
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		vector<pii > v;
		memset(ar,'.',sizeof(ar));
		lpi(i,1,n)
		{
			lpi(j,1,m)
			{
				cin >> ar[i][j];
				if(ar[i][j] == '1' || ar[i][j] == '2' || ar[i][j] == '3')
					v.pb(mp(i,j));
			}
		}
		memset(vis,true,sizeof(vis));
		memset(lev,nax,sizeof(lev));
		lpi(i,0,2)
		{
			bfs(v[i].ff,v[i].ss,i);
		}
		int ans = nax;
		lpi(i,0,n+1)
		{
			lpi(j,0,m+1)
			{
				ans = min(ans,max(lev[i][j][0],max(lev[i][j][1],lev[i][j][2])));
			}
		}
		cout << ans << endl; 
	}
	return 0;
}