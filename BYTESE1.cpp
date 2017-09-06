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
#define pii pair<int, pair<int,int> >
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

int n,m,dx,dy,tim;
int grid[105][105];
int ar[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		bool flag=true;
		cin >> n >> m;
		lpi(i,0,n-1)
		{
			lpi(j,0,m-1)
				cin >> grid[i][j];
		}
		cin >> dx >> dy >> tim;
		dx--, dy--;
		vector<vector<int> > dp(n,vector<int>(m,9999));
		priority_queue<pii , vector<pii > , greater<pii > > q;
		q.push(mp(grid[0][0], mp(0,0)));
		dp[0][0] = grid[0][0];
		while(!q.empty())
		{
			pii p = q.top();
			q.pop();
			//cout << p.ss.ff << " " << p.ss.ss << endl;
			if(p.ss.ff == dx && p.ss.ss == dy)
			{
				cout << "YES" << endl << (tim-p.ff) << endl;
				flag = false;
				break;
			}
			lpi(i,0,3)
			{
				int x=p.ss.ff+ar[i][0], y=p.ss.ss+ar[i][1];
				if(x>=0 && x<n && y>=0 && y<m && (p.ff+grid[x][y])<=tim && dp[x][y]>p.ff+grid[x][y])
				{
					dp[x][y] = p.ff+grid[x][y];
					q.push(mp(dp[x][y], mp(x,y)));
				}
			}
		}
		if(flag)
			cout << "NO" << endl;
	}
	
	return 0;
}