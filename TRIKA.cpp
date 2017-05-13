#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

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
#define lpl(i,a,b) for(lli i=a;i<=b;++i)
#define lplr(i,a,b) for(lli i=a;i>=b;--i)
#define lpv(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)

using namespace std;
typedef long long int lli;


int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int n,m,sx,sy;
	cin >> n >> m;
	cin >> sx >> sy;
	int ar[n+1][m+1];
	lpi(i,1,n)
	{
		lpi(j,1,m)
		{
			cin >> ar[i][j];
		}
	}
	lpi(i,sx+1,n)
	{
		ar[i][sy] = ar[i-1][sy]-ar[i][sy];
	}
	lpi(i,sy+1,m)
	{
		ar[sx][i] = ar[sx][i-1]-ar[sx][i];
	}
	lpi(i,sx+1,n)
	{
		lpi(j,sy+1,m)
		{
			ar[i][j] = max(ar[i-1][j] - ar[i][j] , ar[i][j-1] - ar[i][j]);
		}
	}/*
	lpi(i,1,n)
	{
		lpi(j,1,m)
		{
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}*/
	if(ar[n][m]>=0)
		cout <<"Y " << ar[n][m];
	else
		cout << "N";
	return 0;
}
