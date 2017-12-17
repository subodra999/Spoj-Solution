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
#define test() int t; scanf("%d",&t); while(t--)


using namespace std;
typedef long long int ll;
const int N =(int) 5e2+4;
set<string> SET;

int main()
{
	int n,box;
	while(1)
	{
		cin >> n >> box;
		if(n == -1)
			return 0;
		ll ar[n], mx=0;
		lpi(i,0,n-1)
		{
			cin >> ar[i];
			mx = max(mx, ar[i]);	
		}	
		ll low=1,high=mx,ans=0;
		while(low <= high)
		{
			ll mid = (low+high)/2;
			ll curr=0;
			lpi(i,0,n-1)
			{
				curr += (ll)ceil(ar[i]/(1.0*mid));
			}
			if(curr<=box)
			{
				ans = mid;
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}