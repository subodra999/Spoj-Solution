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
// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
int inv(int a)
{
    int x, y;
    int g = gcdExtended(a, mod, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        int res = (x%mod + mod) % mod;
        return res;
    }
}
 
 
lli comb(lli n,lli k)
{
	lli ans=1,j=1;
	k = max(k,n-k);
	for(lli i=n;i>k;--i)
	{
		ans = (ans*i)%mod;
		if(j<=(n-k))
		{
			ans = (ans*inv(j))%mod;
			j++;
		}
	}
	if(j<=(n-k))
		{
			ans = (ans*inv(j))%mod;
			j++;
		}
	/*for(lli i=2;i<=(n-k);++i)
		ans /= i;*/
	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	lli n;
	vll a(3);
	cin >> n >> a[0] >> a[1] >> a[2];
	sort(a.rbegin(),a.rend());
	lli ans1 = comb(n,a[0]);
	lli ans2 = comb(n-a[0],a[1]);
	lli ans3 = comb(n-a[0]-a[1],a[2]);
	lli ans = ((ans1%mod * ans2%mod)%mod * ans3%mod)%mod;
	cout << ans;
	return 0;
}
