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
char ar[101][101];
bool visit[101][101];
int dist=0,r,c;
int level[101][101];
bool bfs(int x,int y,int d_x,int d_y,int l)
{
	if(x<1 || y<1)
		return false;
	if(x>r || y>c)
		return false;
	if(ar[x][y] == '*')
		return false;
	if(!visit[x][y])
		return false;
    level[x][y] = l;
	if(x == d_x && y == d_y)
		return true;
	visit[x][y] = false;
    if(bfs(x-1,y,d_x,d_y,l+1))
		return true;
	if(bfs(x+1,y,d_x,d_y,l+1))
	 	return true;
	if(bfs(x,y-1,d_x,d_y,l+1))
		return true;
	if(bfs(x,y+1,d_x,d_y,l+1))
		return true;
	
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int t,e_x,e_y,d_x,d_y;
	cin >> t;
	while(t--)
	{
		cin >> r >> c;
		lpi(i,1,r)
		{
			lpi(j,1,c)
			{
				cin >> ar[i][j];
              //  cout << "i" << endl;
				visit[i][j] = true;
				if(ar[i][j] == '$')
				{
					e_x = i;
					e_y = j;
				}
				if(ar[i][j] == '#')
				{
					d_x = i;
					d_y = j;
				}				
			}
		}
		dist = 0;
		if(bfs(e_x,e_y,d_x,d_y,0))
			cout << level[d_x][d_y] << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}
