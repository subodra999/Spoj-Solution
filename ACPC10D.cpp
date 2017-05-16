#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<queue>
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
	//cout << "hello";
	int t=0;
	while(1)
	{
		int n;
		cin >> n;
		if(n==0)
			return 0;
		int ar[n][3];
		int T[n][3];
		lpi(i,0,n-1)
		{
			lpi(j,0,2)
			{
				cin >> ar[i][j];
			}
		}
		//Base cases :
		T[1][0] = ar[0][1]+ar[1][0];
		T[1][1] = min(T[1][0] , min(ar[0][1] , ar[0][1]+ar[0][2]))+ar[1][1];
		T[1][2] = min(T[1][1] , min(ar[0][1] , ar[0][1]+ar[0][2]))+ar[1][2];

		lpi(i,2,n-1)
		{
			T[i][0] = min(T[i-1][0],T[i-1][1]) + ar[i][0];
			T[i][1] = min(T[i][0] , min(T[i-1][0] , min(T[i-1][1] , T[i-1][2]))) + ar[i][1];
			T[i][2] = min(T[i][1] , min(T[i-1][1] , T[i-1][2])) + ar[i][2];
		}
		t++;
		cout << t <<". " << T[n-1][1] << endl;
	}

	return 0;
}
