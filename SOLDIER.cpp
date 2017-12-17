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
#define speed ios::sync_with_stdio(false)

using namespace std;
typedef long long int ll;
vector<pii> adj[7];
int t;

int recur(int type,int cost,int quality)
{
	if(type == 7)
	{
		return quality;
	}
	int flag = 0, ans = 0;
	for(int i=0;i<adj[type].size();i++)
	{
		if(cost+adj[type][i].ff < t)
		{
			int temp = recur(type+1,cost+adj[type][i].ff,adj[type][i].ss);
			if(temp != -1)
			{
				flag = 1;
				ans = max(ans, temp);
			}
		}
	}
	if(flag)
		return min(ans, quality);
	else
		return -1;
}
int main()
{
	int n,a,b,c;
	cin >> n >> t;
	lpi(i,0,n-1)
	{
		cin >> a >> b >> c;
		if(a>=1 && a<=6)
		{
			adj[a].pb(mp(b,c));
		}
	}
	int ans = 0 , flag=1;
	for(int i=0;i<adj[1].size();i++)
	{
		int temp = recur(2,adj[1][i].ff,adj[1][i].ss);
		if(temp != -1)
		{
			flag = 0;
			ans = max(ans, temp);
		}
	}
	if(flag)
		cout << 0;
	else
		cout << ans;
	return 0;
}