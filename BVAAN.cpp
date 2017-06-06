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

string func(string a,string b)
{
	int la = a.length();
	int lb = b.length();
	int T[la+1][lb+1];
	lpi(i,0,la)
	{
		lpi(j,0,lb)
		{
			if(i == 0 || j == 0)
				T[i][j] = 0;
			else if(a[i-1] == b[j-1])
				T[i][j] = T[i-1][j-1]+1;
			else 
				T[i][j] = max(T[i-1][j],T[i][j-1]);
		}
	}
		int i=la,j=lb;
		string str="";
		while(i>0 && j>0)
		{
			if(a[i-1] == b[j-1])
			{
				str += a[i-1];
				i--;
				j--;
			}
			else if(T[i][j] == T[i-1][j])
				i--;
			else if(T[i][j] == T[i][j-1])
				j--;
		}
	
	return str;
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int t;
	cin >> t;
	while(t--)
	{
		string a,b;
		int k;
		cin >> a >> b >> k;
		string lcs = func(a,b);
		sort(lcs.rbegin(),lcs.rend());
		int sum=0;
		if(lcs.length() < k)
		{
			cout << 0 << endl;
		}
		else
		{
			lpi(i,0,k-1)
			{
				sum += lcs[i];
			}
			cout << sum << endl;
		}
	}
	return 0;
}
