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
int ar[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
int grid[1003][1003];
int vis[1003][1003];

int bfs(int str,int en, int cnt)
{
	queue<pii > q;
	q.push(mp(str,en));
	vis[str][en] = cnt;
	while(!q.empty())
	{
		pii p = q.front();
		q.pop();
		int x = p.ff+ar[grid[p.ff][p.ss]][0], y = p.ss + ar[grid[p.ff][p.ss]][1];
		if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==-1)
		{
			q.push(mp(x,y));
			vis[x][y] = cnt;
		}
		else
		{
			if(vis[x][y] == cnt)
				return 1;
			else
				return 0;
		}
	}

}
int main()
{
	char c;
	cin >> n >> m;
	lpi(i,0,n-1)
	{
		lpi(j,0,m-1)
		{
			cin >> c;
			if(c == 'N')
				grid[i][j] = 0;
			else if(c == 'S')
				grid[i][j] = 1;
			else if(c == 'E')
				grid[i][j] = 2;
			else
				grid[i][j] = 3;
		}
	}
	int ans = 0, cnt = 1;
	memset(vis,-1,sizeof(vis));
	lpi(i,0,n-1)
	{
		lpi(j,0,m-1)
		{
			if(vis[i][j] == -1)
			{
				ans += bfs(i,j,cnt++);
			}
		}
	}
	cout << ans;
	return 0;
}