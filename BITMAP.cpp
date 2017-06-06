#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>

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
#define lpl(i,a,b) for(lli i=a;i<=b;++i)
#define lplr(i,a,b) for(lli i=a;i>=b;--i)
#define lpv(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)

using namespace std;
typedef long long int lli;

int bit[185][185];
bool vis[185][185];
int lev[185][185];
int m,n;
void bfs(int r,int c)
{
	queue<pii> que;
	que.push(mp(r,c));
	lev[r][c] = 0;
	while(!que.empty())
	{
		pii p = que.front();
		vis[p.ff][p.ss] = false;
		que.pop();
		//4 cases :
		if(p.ff+1 < m && vis[p.ff+1][p.ss] && bit[p.ff+1][p.ss] == 0)
		{
			if(lev[p.ff+1][p.ss] > lev[p.ff][p.ss]+1)
			{
				que.push(mp(p.ff+1,p.ss));
				lev[p.ff+1][p.ss] = lev[p.ff][p.ss]+1;
			}
		}	
		if(p.ff-1 >=0 && vis[p.ff-1][p.ss] && bit[p.ff-1][p.ss] == 0)
		{
			if(lev[p.ff-1][p.ss] > lev[p.ff][p.ss]+1)
			{
				lev[p.ff-1][p.ss] = lev[p.ff][p.ss]+1;
				que.push(mp(p.ff-1,p.ss));
			}
		}	
		if(p.ss+1 < n && vis[p.ff][p.ss+1] && bit[p.ff][p.ss+1] == 0)
		{
			if(lev[p.ff][p.ss+1] > lev[p.ff][p.ss]+1)
			{
				lev[p.ff][p.ss+1] = lev[p.ff][p.ss]+1;	
				que.push(mp(p.ff,p.ss+1));
			}
		}	
		if(p.ss-1>=0 && vis[p.ff][p.ss-1] && bit[p.ff][p.ss-1] == 0)
		{
			if(lev[p.ff][p.ss-1] > lev[p.ff][p.ss]+1)
			{
				lev[p.ff][p.ss-1] = lev[p.ff][p.ss]+1;	
				que.push(mp(p.ff,p.ss-1));
			}
		}	

	}	
}


int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int test;
	cin >> test;
	lpi(t,1,test)
	{
		memset(lev,nax,sizeof(lev));
		cin >> m >> n;
		lpi(i,0,m-1)
		{
			string s;
			cin >> s;
			lpi(j,0,n-1)
			{
				bit[i][j] = s[j]-'0';
			}
		}
		lpi(i,0,m-1)
		{
			lpi(j,0,n-1)
			{
				if(bit[i][j] == 1)
				{
					memset(vis,true,sizeof(vis));
					bfs(i,j);
				}	
			}
		}
		lpi(i,0,m-1)
		{
			lpi(j,0,n-1)
			{
				cout << lev[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
