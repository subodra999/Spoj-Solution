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
#define sll set<long long int>
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mis map<int,string>
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define lpi(i,a,b) for(int i=a;i<=b;i++)
#define lpir(i,a,b) for(int i=a;i>=b;i--)
#define lpl(i,a,b) for(lli i=a;i<=b;++i)
#define lplr(i,a,b) for(lli i=a;i>=b;--i)
#define lpv(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)

using namespace std;

typedef unsigned long long int ull;
typedef long long int lli;
typedef vector<vector<lli> > mat;

vector<pii > v[100001];
int ans = 0,ansd=0;
pair<int,int>  dfs(int n,int d)
{
	vector<bool> visit(100001,true);
	int node = n;
	stack<pair<int,int> >s;
	s.push(make_pair(n,0));
	visit[n] = false;
	while(!s.empty())
	{
		pair<int,int> p = s.top();
		if(d<p.ss)
		{
			d = p.ss;
			node = p.ff;
		}
		s.pop();
		for(vector<pii >::iterator it=v[p.ff].begin();it!=v[p.ff].end();it++)
		{
			if(visit[(*it).ff])
			{
				s.push(make_pair((*it).ff,p.ss+(*it).ss));
				visit[p.ff] = false;
			}
		}
	}
	return make_pair(d,node);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,x,y,c;
		cin >> n;
		lpi(i,0,n)
		{
			v[i].clear();
		}
		lpi(i,2,n)
		{
			cin >> x >> y >> c;
			v[x].pb(mp(y,c));
			v[y].pb(mp(x,c));
		}
		pair<int,int> pa = dfs(1,0);
		pair<int,int> fi = dfs(pa.ss,0);
		pa.ff > fi.ff ? cout << pa.ff : cout << fi.ff;
		cout << endl;
		
	}
	return 0;
}