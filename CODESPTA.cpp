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
lli count1(lli n)
{
//	cout << n << " " <<  noSetBit(n) << endl;
	return noSetBit(n);
}
lli count2(lli n)
{
	lli m=n;
	vector<int> v;
	while(n)
	{
		v.push_back(n%2);
		n/= 2;
	}
	lli i=0;
	while(v[i] != 1)
	{
		i++;
	}
	lli j = i;
	while(i<v.size())
	{
		if(v[++i] == 1)
			j++;
	}
//	cout << m << " " << (32-j) << endl;
	return (32-j);
	
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	lli t , x , y ;
	cin >> t;
	while(t--)
	{
		lli ans =0;
		cin >> x >> y;
		lpi(i,x,y)
		{
			if(i<0)
			{
				ans+= count2(abs(i));
			}
			else
			{
				ans+= count1(i);
			}
		}
	cout << ans << endl;
	}
	return 0;
}
