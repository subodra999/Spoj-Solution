#define speed ios::sync_with_stdio(false)
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
#define test() int t; cin >> t; while(t--)

using namespace std;
typedef long long int ll;

const int N = (int)1e5+5;


int main()
{
	test()
	{
		int n;
		cin >> n;
		int ar[n];
		lpi(i,0,n-1)
			cin >> ar[i];
		vii lis(n,1),lds(n,1);
		lpi(i,1,n-1)
		{
			lpi(j,0,i-1)
			{
				if(ar[j]<ar[i])
				{
					lis[i] = max(lis[i],lis[j]+1);
				}
			}
		}
		lpir(i,n-2,0)
		{
			lpir(j,n-1,i+1)
			{
				if(ar[j]<ar[i])
				{
					lds[i] = max(lds[i],lds[j]+1);
				}
			}
		}
		int ans = 0;
		lpi(i,0,n-1)
		{
			ans = max(ans, lis[i]+lds[i]-1);
		}
		cout << ans << endl;
	}
	return 0;
}