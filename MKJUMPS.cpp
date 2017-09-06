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

int ar[8][2] = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};
bool chess[15][15];
int row,s,e;
int col[15][2];
int ans=0;


void dfs(int str,int en,int len)
{
	ans = max(ans,len);
	lpi(i,0,7)
	{
		int x=str+ar[i][0], y=ar[i][1]+en;
		if(x>=0 && x<row && y>=col[x][0] && y<=col[x][1] && chess[x][y])
		{
			chess[x][y] = false;
			dfs(x,y,len+1);
		}
	}
	chess[str][en] = true;
}

int main()
{
	int t=0;
	while(1)
	{
		t++;
		int str;
		cin >> row;
		if(row==0)
			return 0;
		memset(chess, false, sizeof(chess));
		int cnt=0;
		lpi(i,0,row-1)
		{
			cin >> s >> e;
			if(i==0)
				str = s;
			col[i][0] = s, col[i][1] = s+e-1;
			lpi(j,s,s+e-1)
			{
				chess[i][j] = true;
				cnt++;
			}
		}
		//cout << cnt << " ";
		ans = 0;
		chess[0][str] = false;
		dfs(0,str,1);
		if(cnt-ans == 1)
		{
			cout << "Case "<<t<<", "<<cnt-ans<<" square can not be reached."<<endl;
		}
		else
		{
			cout << "Case "<<t<<", "<<cnt-ans<<" squares can not be reached."<<endl;
		}
	}
	
	return 0;
}