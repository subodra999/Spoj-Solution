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
ll dp[10];
void init()
{
	dp[0] = 0;
	dp[1] = 45;
	lpi(i,2,9)
	{
		dp[i] = 10*dp[i-1] + 45*(ll)pow(10,i-1);
		//cout << dp[i] << endl;
	}
}
int length(ll n)
{
	int ans=0;
	while(n)
	{
		ans++;
		n/=10;
	}
	return ans;
}
ll func(ll n,int l)
{
	if(n<=9)
		return (n*(n+1))/2;
	ll cm = dp[l-1];
	ll p = (ll)pow(10,l-1);
	int msd = n/p;
	ll next = n%p;
	ll ans = cm*(msd) + ((msd*(msd-1))/2)*p + msd*(next+1);
	return (ans + func(next,l-1));
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	init();
	ll l,r;
	while(1)
	{
		cin >> l >> r;
		if(l==-1 && r==-1)
			break;
		int l1=length(l-1);
		int r1=length(r);
		ll lsum = func(l-1,l1);
		ll rsum = func(r,r1);
		ll ans = rsum - lsum;
		cout <<ans<< endl; 

	}
	return 0;
}