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
double power(lli x,lli n) { double B=log(x); double C=n*B; return exp(C); }
bool isOdd(lli n){ if(n&1) return 1; return 0; }
lli noSetBit(lli n){ lli cnt=0; while(n){ n&=(n-1); cnt++;} return cnt; }
bool prime[100005];
void seive()
{
	for(int i=2;i*i<100005;i++)
	{
		if(prime[i])
		{
			for(int j=2;i*j<100005;j++)
			{
				prime[i*j] = false;
			}
		}
	}
}
bool check(lli n)
{
	lli m = n*n+2;
	if(m<100005)
		return prime[m];
	else
	{
		for(lli i =2;i*i<=m;i++)
		{
			if(m%i==0)
				return false;
		}
		return true;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	memset(prime,true,sizeof(prime));
	seive();
	int t;
	lli x , y;
	cin >> t;
	while(t--)
	{
		lli cnt=0;
		cin >> x >> y;
		lpi(i,x,y)
		{
			if(i==0 || i==1 || i==2)
				cnt++;
			else if(prime[i])
			{
				if(check(i))
				{
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
