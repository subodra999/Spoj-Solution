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

struct node
{
	int o,n,w;
};

ll oxy,nit,n;
node ar[1006];
ll dp[55][205][1005];

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int t;
	cin >> t;
	while(t--)
	{
		memset(dp,mod,sizeof(dp));
		cin >> oxy >> nit >> n;
		lpi(i,0,n-1)
			cin >> ar[i].o >> ar[i].n >> ar[i].w;
		dp[0][0][0] = 0;
		lpi(i,0,oxy)
		{
			lpi(j,0,nit)
			{
				lpi(k,1,n)
				{
					if(i<ar[k-1].o && j<ar[k-1].n)
						dp[i][j][k] = min(dp[i][j][k-1], dp[0][0][k-1]+ar[k-1].w);
					else if(i<ar[k-1].o)
						dp[i][j][k] = min(dp[i][j][k-1] , dp[0][j-ar[k-1].n][k-1]+ar[k-1].w);
					else if(j<ar[k-1].n)
						dp[i][j][k] = min(dp[i][j][k-1] , dp[i-ar[k-1].o][0][k-1]+ar[k-1].w);
					else
						dp[i][j][k] = min(dp[i][j][k-1], dp[i-ar[k-1].o][j-ar[k-1].n][k-1]+ar[k-1].w);
				}
			}
		}

		ll ans = mod;
		lpi(i,1,n)
		{
			ans = min(ans, dp[oxy][nit][i]);
		}
		cout << ans << endl;
	}
	return 0;
}