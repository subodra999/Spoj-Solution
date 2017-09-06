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
	int m,n;
	cin >> m >> n;
	vector<pii> adj[m*n];
	char ar[n][m];
	vii cow;
	lpi(i,0,n-1)
	{
		lpi(j,0,m-1)
		{
			cin >> ar[i][j];
			if(ar[i][j] == 'C')
				cow.pb(i*m+j);
		}
	}
	int temp[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
	lpi(i,0,n-1)
	{
		lpi(j,0,m-1)
		{
			int p = i*m+j;
			if(ar[i][j] != '*')
			{
				lpi(k,0,3)
				{
					int x=i+temp[k][0], y=j+temp[k][1];
					if(x>=0 && x<n && y>=0 && y<m && ar[x][y]!='*')
					{
						adj[p].pb(mp(x*m+y,k));
					}
				}
			}
		}
	}
	int str = cow[0], des=cow[1];
	vector<vii > dp(n*m,vector<int>(4,10000));
	priority_queue<pair<pii , pii >, vector<pair<pii , pii > >, greater<pair<pii , pii > > > q;
	q.push(mp(mp(0,-1),mp(str,-1)));
	while(!q.empty())
	{
		pair<pii , pii > p = q.top();
		q.pop();
	//	cout << p.ff.ff << " " << p.ss.ff << " " << p.ss.ss << endl;
		if(p.ss.ff == des)
		{
			cout << p.ff.ff;
			return 0;
		}
		tr(adj[p.ss.ff],it)
		{
			if((*it).ff != p.ff.ss)
			{
				if(p.ss.ss==0&&(*it).ss==1 || p.ss.ss==0&&(*it).ss==3 || p.ss.ss==1&&(*it).ss==0 || p.ss.ss==1&&(*it).ss==2 || p.ss.ss==2&&(*it).ss==1 || p.ss.ss==2&&(*it).ss==3 || p.ss.ss==3&&(*it).ss==2 || p.ss.ss==3&&(*it).ss==0)
				{
					if(dp[(*it).ff][(*it).ss]>p.ff.ff+1)
					{
						q.push(mp(mp(p.ff.ff+1,p.ss.ff),mp((*it).ff,(*it).ss)));
						dp[(*it).ff][(*it).ss] = p.ff.ff+1;
					}
				}
				else
				{
					if(dp[(*it).ff][(*it).ss]>p.ff.ff)
					{
						q.push(mp(mp(p.ff.ff,p.ss.ff),mp((*it).ff,(*it).ss)));
						dp[(*it).ff][(*it).ss] = p.ff.ff;
					}
				}
			}
		}
	}
	
	return 0;
}