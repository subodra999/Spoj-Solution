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

int dp[6][100005];
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int n;
	cin >> n;
	int k;
	cin >> k;
	int coin[k];
	lpi(i,0,k-1)
		cin >> coin[i];
	
	memset(dp,0,sizeof(dp));
	int cnt=0;
	for(int i=coin[0];i<=n;i+=coin[0])
	{
		cnt++;
		dp[0][i] = cnt;
	}
	for(int i=1;i<k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cnt = 0;
			int p = dp[i-1][j];
			while(p)
			{
				cnt++;
				dp[i][j+cnt*coin[i]] = max(dp[i][j+cnt*coin[i]],cnt);
				p--;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
			}
		}
	}
	for(int i=0;i<k;i++)
	{
		if(dp[i][n])
		{
			cout << "YES";
			return 0;
		}
	}
	cout <<"NO";
	return 0;
}