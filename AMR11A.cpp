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
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int t,n,m;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		int ar[n][m];
		lpi(i,0,n-1)
		{
			lpi(j,0,m-1)
				cin >> ar[i][j];
		}
		ar[n-1][m-1] = max(1,ar[n-1][m-1]);
		lpir(i,n-2,0)
		{
			ar[i][m-1] = max(1,ar[i+1][m-1]-ar[i][m-1]);
		}
		lpir(i,m-2,0)
		{
			ar[n-1][i] = max(1,ar[n-1][i+1]-ar[n-1][i]);
		}
		lpir(i,n-2,0)
		{
			lpir(j,m-2,0)
			{
				ar[i][j] = max(1, min(ar[i+1][j], ar[i][j+e1])-ar[i][j]);
			}
		}
		cout << ar[0][0] << endl;
	}
	return 0;
}