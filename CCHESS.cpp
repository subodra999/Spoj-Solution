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
	int sx,sy,dx,dy;
	while(cin >> sx >> sy >> dx >> dy)
	{
		int dp[10][10];
		memset(dp,10000,sizeof(dp));
		int ar[8][2] = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};
		queue<pii > q;
		q.push(mp(sx,sy));
		dp[sx][sy] = 0;
		while(!q.empty())
		{
			pii p = q.front();
			//cout << p.ff << " " << p.ss << endl;
			q.pop();
			if(p.ff==dx && p.ss==dy)
				continue;
			lpi(i,0,7)
			{
				int x=p.ff+ar[i][0], y=p.ss+ar[i][1];
				//cout << dp[x][y] << endl;
 				if(x>=0 && x<=7 && y>=0 && y<=7 && (dp[x][y]>(dp[p.ff][p.ss]+x*p.ff+y*p.ss)))
				{
					dp[x][y] = dp[p.ff][p.ss]+x*p.ff+y*p.ss;
					//cout << "y";
					q.push(mp(x,y));
				}
			}
		}
		cout << dp[dx][dy] << endl;
	}
	return 0;
}