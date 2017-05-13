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
vii edge[10001];
vector<bool> visit(10001,true);
vii level(10001);
void bfs(int n)
{
	queue<int> q;
	q.push(n);
	level[n] = 0;
	visit[n] = false;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(vii::iterator it = edge[p].begin(); it!=edge[p].end(); it++)
		{
			if(visit[*it])
			{
				q.push(*it);
				visit[*it] = false;
				level[*it] = level[p]+1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	cin >> t;
	int r,c;
	while(t--)
	{
		cin >> r >> c;
		char s[r+1][c+1];
		int car;
		lpi(i,1,r)
		{
			lpi(j,1,c)
			{
				edge[c*(i-1)+j].clear();
				visit[c*(i-1)+j] = true;
				cin>>s[i][j];
			}
		}
		vii shop;
		lpi(i,1,r)
		{
			lpi(j,1,c)
			{
//				cout << s[i][j] ;
				if(s[i][j] == '.' || s[i][j] == 'S' || s[i][j] == 'C')
				{
					if(s[i][j] == 'S')
						shop.pb(c*(i-1)+j);
					if(s[i][j] == 'C')
						car = c*(i-1) + j;
					if(i+1 <= r)
					{
						if(s[i+1][j] == '.' || s[i+1][j] == 'C' || s[i+1][j] == 'S')
							edge[c*(i-1)+j].pb(c*(i)+j);
					}
					if(i-1 > 0)
					{
						if(s[i-1][j] == '.' || s[i-1][j] == 'C' || s[i-1][j] == 'S')
							edge[c*(i-1)+j].pb(c*(i-2)+j);
					}
					if(j+1 <= c)
					{
						if(s[i][j+1] == '.' || s[i][j+1] == 'C' || s[i][j+1] == 'S')
							edge[c*(i-1)+j].pb(c*(i-1)+j+1);
					}
					if(j-1 > 0)
					{
						if(s[i][j-1] == '.' || s[i][j-1] == 'C' || s[i][j-1] == 'S')
							edge[c*(i-1)+j].pb(c*(i-1)+j-1);
					}
				}
			}
		}
		
		bfs(car);
		vii v;
		tr(shop,it)
		{
			v.pb(level[*it]);
		}
		sort(all(v));
		int ans = 0;
		int si = v.size();
		lpi(i,0,si-2)
			ans+=(2*v[i]);
		ans+=(si*60);
		ans+=v[si-1];
		cout << ans << endl;
	}
	return 0;
}
