#include<bits/stdc++.h>

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

vector<pair<int, long double> > adj[2000];
vector<long double> dp(2000);
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	while(1)
	{
		int n,m;
		cin >> n;
		lpi(i,0,n)
		{
			adj[i].clear();
			dp[i] = 0;
		}
		if(n == 0)
			return 0;
		cin >> m;
		int x,y;
		long double z;
		lpi(i,0,m-1)
		{
			cin >> x >> y >> z;
			adj[x].pb(mp(y,z));
			adj[y].pb(mp(x,z));
		}
		priority_queue<pair<long double,int>, vector<pair<long double,int> > > q;
		q.push(mp(1,1));
		dp[1] = 1;
		while(!q.empty())
		{
			pair<long double,int> p = q.top();
			q.pop();
			if(p.ss == n)
			{
				cout <<fixed<<setprecision(6)<< p.ff*100 << " percent" << endl;
				break;
			}
			for(int i=0;i<adj[p.ss].size();i++)
			{
				pair<int,long double> pp = adj[p.ss][i];

				if(dp[pp.ff] < p.ff*pp.ss)
				{
					dp[pp.ff] = p.ff*pp.ss;
					q.push(mp(dp[pp.ff],pp.ff));
				}
			}
		}
		//cout << "out" << endl;
	}
	
	return 0;
}