#include<bits/stdc++.h>

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
bool isOdd(lli n){ if(n&1) return 1; return 0; }
lli noSetBit(lli n){ lli cnt=0; while(n){ n&=(n-1); cnt++;} return cnt; }
/*vector<bool> prime(1000001,true);
	vll v;
void seive()
{
	for(lli i=2;i*i<=1000000;i++)
	{
		if(prime[i])
		{
			for(lli j=2;i*j<=1000000;j++)
			{
				prime[i*j] = false;
			}
		}
	}

	for(lli i=2;i<=n;i++)
	{
		if(prime[i])
			v.pb(i);
	}


}*/
lli noDiv(lli n)
{
	lli ans = 1;
	while(n%2==0)
	{
		ans++;
		n/=2;
	}
	for(lli i=3;i<=n;i+=3)
	{
		lli cnt = 1;
		while(n%i == 0)
		{
			cnt++;
			n/=i;
		}
		ans*=cnt;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	scanf("%d",&t);
	lli a,b;
	while(t--)
	{
		scanf("%ld %ld",&a,&b);
		lli n = __gcd(a,b);
		printf("%ld\n", noDiv(n));
	}
	return 0;
}