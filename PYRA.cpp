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

int n,ans;
vii adj[10004];
bool vis[10004];

int dfs(int p)
{
	int trm = 0, node=0;
	tr(adj[p], it)
	{
		if(vis[*it])
		{
			vis[*it] = false;
			trm += dfs(*it);
			node ++;
		}
	}
	ans += (trm+node+1);
	return (trm+node+1);
}

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	cin >> t;
	while(t--)
	{
		int x,y;
		cin >> n;
		lpi(i,0,n)
		{
			vis[i] = true;
			adj[i].clear();
		}
		lpi(i,2,n)
		{
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		ans = 0;
		vis[0] = 0;
		dfs(0);
		cout << ans << endl;
	}
	return 0;
}