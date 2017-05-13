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
map<int,string> m;
void init()
{
		m[0] = "0";
	m[1] = "2(0)";
	m[2] = "2";
	m[3] = "2+2(0)";
	m[4] = "2(2)";
	m[5] = "2(2)+2(0)";
	m[6] = "2(2)+2";
	m[7] = "2(2)+2+2(0)";
	m[8] = "2(3)";
	m[9] = "2(3)+2(0)";
	m[10] = "2(3)+2";
	m[11] = "2(3)+2+2(0)";
	m[12] = "2(3)+2(2)";
	m[13] = "2(3)+2(2)+2(0)";
	m[14] = "2(3)+2(2)+2";
	m[15] = "2(3)+2(2)+2+2(0)";
	m[16] = "2(4)";
}
void func(int n)
{
	int i=1,j=0;
	string s=" ";
	while(i<n)
	{
		if(i&n)
		{
			if(s!=" ")
				s="+"+s;
			s="2("+m[j]+")"+s;
		}
		j++;
		i<<=1;
	}
	cout<<n<<"="<<s<<endl;
}
int main()
{
	//137, 1315, 73, 136, 255, 1384, 16385
	ios_base::sync_with_stdio(false); cin.tie(0); 
	init();
	func(137);
	func(1315);
	func(73);
	func(136);
	func(255);
	func(1384);
	func(16385);
	
	return 0;
}
