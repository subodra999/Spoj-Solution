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

void swap(lli *a,lli *b) { lli t=*a;  *b=*a, *a=t; }
bool isOdd(lli n){ if(n&1) return 1; return 0; }
lli noSetBit(lli n){ lli cnt=0; while(n){ n&=(n-1); cnt++;} return cnt; }
vector<int> v[10001];
int ans = 0,ansd=0;
pair<int,int>  dfs(int n,int d)
{
	vector<bool> visit(10001,true);
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
		for(vii::iterator it=v[p.ff].begin();it!=v[p.ff].end();it++)
		{
			if(visit[*it])
			{
				s.push(make_pair(*it,p.ss+1));
				visit[p.ff] = false;
			}
		}
	}
	return make_pair(d,node);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int n,x,y;
	cin >> n;
	lpi(i,2,n)
	{
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	pair<int,int> pa = dfs(1,0);
//	cout << pa.ff << " " << pa.ss << endl;
	pair<int,int> fi = dfs(pa.ss,0);
	pa.ff > fi.ff ? cout << pa.ff : cout << fi.ff;
	return 0;
}
