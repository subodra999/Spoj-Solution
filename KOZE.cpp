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
char ar[251][251];
vector<vector<bool> > visit(251,vector<bool>(251,true));
int r,c,cow=0,wolf=0,ans_wolf=0,ans_cow=0,f=0;
void bfs(int x,int y)
{
	if(x<1 || y<1)
		return ;
	if(x>r || y>c)
		return;
	if(ar[x][y] == '#')
		return ;
	if(!visit[x][y])
		return ;
	if(ar[x][y] == 'k')
		cow++;
	else if(ar[x][y] == 'v')
		wolf++;
	if((x==r || y==c) && ar[x][y]=='.' )
		f=1;
	visit[x][y] = false;
	bfs(x-1,y);
	bfs(x+1,y);
	bfs(x,y-1);
	bfs(x,y+1);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	cin >> r >> c;
	lpi(i,1,r)
	{
		lpi(j,1,c)
			cin >> ar[i][j];
	}
	lpi(i,1,r)
	{
		lpi(j,1,c)
		{
			if(visit[i][j])
			{
				wolf=cow=f=0;
				bfs(i,j);
				if(f)
				{
					ans_wolf+=wolf;
					ans_cow+=cow;
				}
				else
				{
					if(wolf>=cow)
						ans_wolf+=wolf;
					else
						ans_cow+=cow;
				}
			}
		}
	}
	cout << ans_cow << " " << ans_wolf ;
	return 0;
}
