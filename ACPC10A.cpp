/** By- Subodra Banik
					  ----------------->       NIT Silchar 
		*/
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
#define gi(n) scanf("%d",&n)
#define gll(n) scanf("%lld",&n)
#define gst(n) scanf("%s",n)
#define gc(n) cin >> n
#define oi(n) printf("%d",n)
#define oll(n) printf("%lld",n)
#define ost(n) printf("%s",n)
#define oc(n) cout << n
#define os cout<<" "
#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
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
	int a,b,c;
	while(1)
	{
		cin>>a>>b>>c;
		if(a==0 && b==0 && c==0)
			break;
		if((b-a) == (c-b))
			cout<<"AP "<<(2*c-b)<<endl;
		else
			cout<<"GP "<<(c*c)/b<<endl;
	}
	return 0;
}