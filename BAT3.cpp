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
	int tc;
	cin >> tc;
	while(tc--)
	{
		int n,m;
		cin >> n >> m;
		int ar[n];
		lpi(i,0,n-1)
			cin >> ar[i];
		vii temp1(n,1), temp2(n,1);
		lpi(i,0,n-1)
		{
			lpi(j,i+1,n-1)
			{
				if(ar[j]<ar[i])
					temp1[j] = max(temp1[j], temp1[i]+1);
			}
		}
		lpi(i,m+1,n-1)
		{
			lpi(j,i+1,n-1)
			{
				if(ar[i]>ar[j])
					temp2[j] = max(temp2[j], temp2[i]+1);
			}
		}
		int ans = 0;
		lpi(i,0,n-1)
		{
			if(i != m)
				ans = max(ans,temp1[i]);
		}
		lpi(i,m+1,n-1)
		{
			ans = max(ans, temp1[m]+temp2[i]);
		}
		cout << ans << endl;
	}

	return 0;
}