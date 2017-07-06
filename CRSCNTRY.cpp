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

ll fast_exp(ll a,ll b)
{
	if(a==0)
		return 0;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(b%2==0)
	{
		return fast_exp(((a%mod)*(a%mod))%mod,b/2)%mod;
	}
	return ((a%mod)*fast_exp(((a%mod)*(a%mod))%mod,(b-1)/2))%mod;
}

ll comb(ll n,ll k)
{
	ll ans=1,j=1;
	k = max(k,n-k);
	for(ll i=n;i>k;--i)
	{
		ans *= i;
		if(j<=(n-k))
		{
			ans = ans/j;
			j++;
		}
	}
	if(j<=(n-k))
	{
		ans = ans/j;
		j++;
	}
	return ans;
}
vector<vii> v;
int func(vii v1,vii v2)
{
	int l1 = v1.size();
	int l2 = v2.size();
	int dp[l1+1][l2+1];
	lpi(i,0,l1)
		dp[i][0] = 0;
	lpi(i,0,l2)
		dp[0][i] = 0;
	int ans=0;
	lpi(i,0,l1-1)
	{
		lpi(j,0,l2-1)
		{
			if(v1[i] == v2[j])
			{
				dp[i+1][j+1] = dp[i][j]+1;
			}
			else
			{
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}
			ans = max(ans,dp[i+1][j+1]);
		}
	}
	return ans;
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int t;
	cin >> t;
	while(t--)
	{
		v.clear();
		while(1)
		{
			int n;
			cin >> n;
			if(n == 0)
				break;
			vii v1;
			v1.push_back(n);
			while(1)
			{
				cin >> n;
				if(n == 0)
				{
					v.pb(v1);
					break;
				}
				v1.push_back(n);
			}
		}
		int n = v.size();
		int ans=0;
		lpi(i,1,n-1)
		{
			ans = max(ans,func(v[0],v[i]));
		}
		cout << ans << endl;
	}
	return 0;
}