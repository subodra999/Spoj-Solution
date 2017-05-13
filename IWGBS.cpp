#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<map>
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

string sum(string s1,string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	int l3 = max(l1,l2);
	string s = "";
	int i=l1;
	int j=l2;
	int a,b,su,c=0;
	while(i&&j)
	{
		a = s1[i-1]-'0';
		b = s2[j-1]-'0';
		su = a+b+c;
		c = su/10;
		su %= 10;
		char ch = '0'+su;
		s = ch+s;
		i--;
		j--;
	}
	while(i)
	{
		a = s1[i-1]-'0';
		su = a + c;
		c = su/10;
		su %= 10;
		char ch = '0'+su;
		s = ch+s;
		i--;
	}
	while(j)
	{
		b = s2[j-1]-'0';
		su = b + c;
		c = su/10;
		su %= 10;
		char ch = '0'+su;
		s = ch+s;
		j--;
	}
	if(c)
	{
		char ch = '0'+c;
		s = ch+s;
	}
	return s;
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int n;
	cin >> n;
	string dp[n][2];
	dp[0][0] = dp[0][1] = "1";
	lpl(i,1,n-1)
	{
		dp[i][0] = dp[i-1][1];
		dp[i][1] = sum(dp[i-1][0],dp[i-1][1]);
	}
	cout << sum(dp[n-1][0],dp[n-1][1]);
	return 0;
}
