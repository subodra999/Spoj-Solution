#include<bits/stdc++.h>

#define mod 10000007
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
#define sll set<long long int>
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mis map<int,string>
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define lpi(i,a,b) for(int i=a;i<=b;i++)
#define lpir(i,a,b) for(int i=a;i>=b;i--)
#define lpl(i,a,b) for(lli i=a;i<=b;++i)
#define lplr(i,a,b) for(lli i=a;i>=b;--i)
#define lpv(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)

using namespace std;

typedef unsigned long long int ull;
typedef long long int lli;
typedef vector<vector<lli> > mat;

void swap(lli *a,lli *b) { lli t=*a;  *b=*a, *a=t; }
double power(lli x,lli n) { double B=log(x); double C=n*B; return exp(C); }
bool isOdd(lli n){ if(n&1) return 1; return 0; }
lli noSetBit(lli n){ lli cnt=0; while(n){ n&=(n-1); cnt++;} return cnt; }

lli ex(lli x , lli n)
{
	if(n==0)
	return 1;
	if(n&1)
	{
		return (x * ex((x*x)%mod , (n-1)/2) )%mod;
	}
	return ex((x*x)%mod , n/2);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	lli n,k;
	while(1)
	{
		cin >> n >> k;
		if(n==0 && k==0)
		break;
		lli a = (2 * ex((n-1),k))%mod;
		lli b = ex(n,k)%mod;
		lli c = (2*ex((n-1),(n-1)))%mod;
		lli d = ex(n,n)%mod;
		cout << ((a+b)%mod+(c+d)%mod)%mod <<endl;
	}
	return 0;
}
