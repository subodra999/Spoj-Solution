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
ll set_one(ll a)
{
	ll ans=0;
	while(a)
	{
		a = a&(a-1);
		ans++;
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int g[n][n];
		lpi(i,0,n-1)
		{
			lpi(j,0,n-1)
			{
				cin >> g[i][j];
			}
		}
		int x,y,x1,y1,xx,yy;
		cin >> x >> y >> x1 >> y1;
		int ar[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
		ll limit = 1<<11;
		bool vis[n][n];
		ll ans = 11;
		lpl(mask,1,limit-1)
		{
			memset(vis,true,sizeof(vis));
			queue<pii > q;
			if(mask&(1<<g[x][y]))
			{
				q.push(mp(x,y));
				vis[x][y] = false;
			}
			while(!q.empty())
			{
				pii p = q.front();
				q.pop();
				if(p.ff == x1 && p.ss == y1)
				{
					ans = min(ans,set_one(mask));
					break;
				}
				for(int i=0;i<=3;i++)
				{
					xx=p.ff+ar[i][0], yy=p.ss+ar[i][1];
					if(xx<n && xx>=0 && yy<n && yy>=0)
					{
						ll mask1 = 1<<g[xx][yy];
						if(vis[xx][yy])
						{
							if(mask&mask1)
							{
								vis[xx][yy] = false;
								q.push(mp(xx,yy));
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}