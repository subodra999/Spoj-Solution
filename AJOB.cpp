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

int p;


int n,d,l,m;
void extendedeuclid(int a,int b)
{
	int temp;
	if(b==0)
	{
		d = a;
		l = 1;
		m = 0;
	}
	else
	{
		extendedeuclid(b,a%b);
		temp = l;
		l = m;
		m = temp - (a/b)*m;
	}
}

int inverse(int a,int b)
{
	extendedeuclid(a,b);
	return (l%b + b)%b;
}

int nCrModpDP(int n, int r)
{
	r = min(r,n-r);
	int ans = 1;
	for(int i=1;i<=r;++i)
	{
		ans = (ans * n);
		ans /= i;	
		n--;
	}
	return ans;
}

int nCrModpLucas(lli n, lli r)
{
   if (r==0)
      return 1;
   int ni = n%p, ri = r%p;
   int rem = nCrModpLucas(n/p, r/p);
   return (rem * nCrModpDP(ni, ri));  
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	cin >> t;
	while(t--)
	{
		lli n,k;
		cin >> n >> k >> p;
		if(n<k)
		{
			cout << 0 << endl;
		}
		else
		{
			lli ans=0;
			for(lli i=k; i<=n; ++i)
			{
				int rem = nCrModpLucas(i,i-k);
				ans = (ans + rem);
			}
			cout << "ans : " << ans%p << endl;
		}
	}
	return 0;
}
