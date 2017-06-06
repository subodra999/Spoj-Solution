#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>

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

int r,c;
char s[51][51];
int func(int i,int j,int l,char a)
{
	if(s[i][j] == a)
	{
		a++;
		int b,c,d,e,f,g,h,i;
		if(j-1 >=0)
		{
			if(i-1 >= 0)
				i = func(i-1,j-1,l+1,a);
			b = func(i,j-1,l+1,a);
			if(i+1 < r)
				c = func(i+1,j-1,l+1,a);
		}
		if(i-1 >= 0)
			d = func(i-1,j,l+1,a);
		if(i+1 < r)
			e = func(i+1,j,l+1,a);
		if(j+1 < c)
		{
			if(i-1 >= 0)
				f = func(i-1,j+1,l+1,a);
			g = func(i,j+1,l+1,a);
			if(i+1 < r)
				h = func(i+1,j+1,l+1,a);
		}
		return max(b,max(c,max(d,max(e,max(f,max(g,max(h,i)))))));
	}
	return l;
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	while(1)
	{
		cin >> r >> c;
		if(r == 0 && c == 0)
			return 0;
		lpi(i,0,r-1)
		{
			lpi(j,0,c-1)
			{
				cin >> s[i][j];
			}
		}
		int ans = 0;
		lpi(i,0,r-1)
		{
			lpi(j,0,c-1)
			{
				if(s[i][j] == 'A')
					ans = max(ans,func(i,j,0,s[i][j]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
