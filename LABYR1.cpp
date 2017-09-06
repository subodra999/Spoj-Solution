
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
int temp[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
char ar[1005][1005];
bool vis[1005][1005];
int ans=0,n,m;
pii p;
void dfs(int str,int en,int len)
{
	if(ans<len)
	{
		ans = len;
		p.ff = str, p.ss = en;
	}
	lpi(i,0,3)
	{
		int x=str+temp[i][0], y=temp[i][1]+en;
		if(x>=0 && x<n && y>=0 && y<m && ar[x][y]=='.' && vis[x][y])
		{
			vis[x][y] = false;
			dfs(x,y,len+1);
		}
	}
	vis[str][en] = true;
}

void dfs2(int str,int en)
{
	lpi(i,0,3)
	{
		int x=str+temp[i][0], y=temp[i][1]+en;
		if(x>=0 && x<n && y>=0 && y<m && ar[x][y]=='.' && vis[x][y])
		{
			vis[x][y] = false;
			dfs2(x,y);
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> m >> n;
		memset(vis,true,sizeof(vis));

		lpi(i,0,n-1)
		{
			lpi(j,0,m-1)
				cin >> ar[i][j];
		}
		ans = 0;
		lpi(i,0,n-1)
		{
			lpi(j,0,m-1)
			{
				if(ar[i][j]=='.' && vis[i][j])
				{
					vis[i][j] = false;
					dfs(i,j,1);
					dfs(p.ff,p.ss,1);
					dfs2(i,j);
				}
			}
		}

		cout << "Maximum rope length is "<< ans-1 <<"." << endl;
	}
	return 0;
}