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

int main()
{
	int n,m,t=1;
	while(1)
	{
		cin >> n >> m;
		if(n==0 && m==0)
			break;
		vector<string> ar(n);
		vector<vii> dp(n,vii(m,0));
		lpi(i,0,n-1)
			cin >> ar[i] ;
		char s='A';
		int ans=0;
		int len = 0;
		while(s<='Z')
		{
			lpi(i,0,n-1)
			{
				lpi(j,0,m-1)
				{
					if(ar[i][j] == s)
					{
						int curr = 0;
						if(i-1>=0)
						{
							if(j-1>=0)
							{
								if(dp[i-1][j-1] == len)
									curr = max(dp[i-1][j-1] , curr);
							}
							if(dp[i-1][j] == len)
								curr = max(dp[i-1][j] , curr);
							if(j+1<m)
							{
								if(dp[i-1][j+1])
									curr = max(dp[i-1][j+1] , curr); 
							}	
						}
						if(j-1>=0)
						{
							if(dp[i][j-1] == len)
								curr = max(dp[i][j-1] , curr);
						}
						if(j+1<m)
						{
							if(dp[i][j+1] == len)
								curr = max(dp[i][j+1] , curr);
						}
						if(i+1<n)
						{
							if(j-1>=0)
							{
								if(dp[i+1][j-1] == len)
									curr = max(dp[i+1][j-1] , curr);
							}
							if(dp[i+1][j] == len)
								curr = max(dp[i+1][j] , curr);
							if(j+1<m)
							{
								if(dp[i+1][j+1])
									curr = max(dp[i+1][j+1] , curr); 
							}	
						}
						if(curr == len)
							dp[i][j] = curr+1;
						ans = max(ans,dp[i][j]);
					}
				}
			}
			s++;
			len++;
		}
		cout << "Case "<<t << ": " <<ans << endl;
		t++;
	}
	return 0;
}