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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	while(1)
	{
		int n,m,ans=0,sl=0,sr=0;
		cin >> n;
		if(n==0)
			return 0;
		int a[n] ;
		lpi(i,0,n-1)
			cin >> a[i];
		cin >> m;
		int b[m];
		lpi(i,0,m-1)
			cin >> b[i];
		int i=0 , j=0 ;
		while(i<n && j<m)
		{
			if(a[i] == b[j])
			{
				ans+= max(sl , sr);
				sl = sr = 0;
				ans+= a[i];
				i++;
				j++;
			}
			else
			{
				if(a[i] < b[j])
				{
					sl+= a[i++];
				}
				else
				{
					sr+= b[j++];
				}
			}
		}
		while(i<n)
		{
			sl+=a[i++];
		}
		while(j<m)
		{
			sr+=b[j++];
		}
		ans+= max(sr , sl);
		cout << ans << endl;
	}
	return 0;
}
