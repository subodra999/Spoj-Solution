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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int t,o,n;
	string s;
	cin >> t;
	while(t--)
	{
		cin >> o >> n;
		cin >> s;
		bool ar[o];
		lpi(i,0,o-1)
			ar[i] = true;
		int no_move = o-n;
		int sh_move = ceil(no_move/2.0);
		int di_move = floor(no_move/2.0);
		lpi(i,0,o-1)
		{
			if(sh_move && s[i] == '1')
			{
				ar[i] = false;
				sh_move--;
			}
			if(di_move && s[i] == '0')
			{
				ar[i] = false;
				di_move--;
			}
		}
		int k=0;
		while(sh_move)
		{
			if(ar[k] && s[k] == '0')
			{
				ar[k] = false;
				sh_move--;
			}
			k++;
		}
		while(di_move)
		{
			if(ar[k] && s[k] == '1')
			{
				ar[k] = false;
				di_move--;
			}
			k++;
		}
		lpi(i,0,o-1)
		{
			if(ar[i])
				cout << s[i];
		}
		cout << endl;
			
	}
	return 0;
}
