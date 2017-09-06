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

ll set_one(ll a)
{
	ll ans=0;
	while(a)
	{
		a = a&(a-1);
		ans++;
	}
	return ans;
}

ll d,x,y;
void extendedeuclid(ll a,ll b)
{
    ll temp;
    if(!b)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        extendedeuclid(b,a%b);
        temp = x;
        x = y;
        y = temp-(a/b)*y;
    }
}

ll modinverse(ll a,ll b)
{
    extendedeuclid(a,b);
    return (x%b+b)%b;
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
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int n,m;
	while(1)
	{
		cin >> n >> m;
		int dp[n];
		if(n|m)
		{
			int candy[m];
			lpi(i,0,n-1)
			{
				lpi(j,0,m-1)
				{
					cin >> candy[j];
				}
				if(m>1)
					candy[1] = max(candy[1],candy[0]);
				lpi(j,2,m-1)
				{
					candy[j] = max(candy[j-1],candy[j-2]+candy[j]);
				}
				dp[i] = candy[m-1];
			}
			if(n>1)
				dp[1] = max(dp[1],dp[0]);
			lpi(i,2,n-1)
			{
				dp[i] = max(dp[i-1], dp[i-2]+dp[i]);
			}
			cout << dp[n-1] << endl;
		}
		else
			return 0;
	}
	return 0;
}