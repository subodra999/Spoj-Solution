#include<bits/stdc++.h>

#define mod 1000000007
#define nax 1000005
#define inf 100000000000000000LL
#define pb push_back
#define mp make_pair
#define in insert
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define vii vector<int>
#define vll vector<long long int>
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
#define lpvi(it1,it2,it) for(vii::iterator it=it1;it!=it2;it++)
using namespace std;

typedef unsigned long long int ull;
typedef long long int lli;
typedef vector<vector<lli> > mat;

void swap(lli *a,lli *b) { lli t=*a;  *b=*a, *a=t; }
bool isOdd(lli n){ if(n&1) return 1; return 0; }
lli noSetBit(lli n){ lli cnt=0; while(n){ n&=(n-1); cnt++;} return cnt; }
bool prime[50001];
vii v;
void seive()
{
	lpi(i,2,50000)
	{
		if(prime[i])
		{
			v.push_back(i);
			for(int j=2;i*j<50001;j++)
				prime[j*i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	memset(prime , true , sizeof(prime));
	seive();
	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vii::iterator it1 = upper_bound(v.begin(),v.end(),n);
		vii::iterator it;
		lli ans = 1;
		lpvi(v.begin(),it1,it)
		{
			int p = *it , i=1 , j=pow(p,i) , cnt=0;
			while(n/j)
			{
				cnt+=(n/j);
				i++;
				j= pow(p,i);
			}
			ans = (ans * (cnt+1))%mod;
		}
		cout << ans << endl;
	}
	return 0;
}
