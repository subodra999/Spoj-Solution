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

vll v[1000005] , level(1000005);
bool bfs(lli p,lli l)
{
		queue<lli> q;
		q.push(p);
		if(level[p] != -1)
			return false;
		vector<bool> visit(1000005 , true);
		level[p] = 0;
		visit[p] = false;
		lli i = 0;
		while(!q.empty() && i<l)
		{
			lli par = q.front();
			q.pop();
			for(vll::iterator it = v[par].begin() ; it!=v[par].end() ; it++)
			{
				if(visit[*it])
				{
					q.push(*it);
					visit[*it] = false;
					if(level[*it] != -1)
						return false;
					level[*it] = level[par]+1;
				}
			}
			i = level[par]+1;
		}
		return true;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	cin >> t;
	while(t--)
	{
		lli n,m,r;
		cin >> n >> m >> r;
		lpl(i,1,n)
		{
			v[i].clear();
			level[i] = -1;
		}
		lli x,y,l;
		lpl(i,1,m)
		{
			cin >> x >> y;
			v[x].pb(y);
			v[y].pb(x);
		}
		int f=1;
		lli ar[r+1][2];
		lpi(i,1,r)
		{
			cin >> ar[i][0] >> ar[i][1];
		}
		lpl(i,1,r)
		{
			if(bfs(ar[i][0],ar[i][1]))
				continue;
			cout << "No"  << endl;
			f=0;
			break;
		}
		if(f)
		{
			lpl(i,1,n)
			{
				cout << level[i]<<" ";
				if(level[i] == -1)
				{
					cout << "No" << endl;
					f=0;
					break;
				}
			}
			if(f)
			{
				cout << "Yes" << endl;
			}
		}
	}
	return 0;
}
