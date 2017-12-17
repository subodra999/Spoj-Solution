#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>


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
#define lpl(i,a,b) for(ll i=a;i<=b;++i)
#define lplr(i,a,b) for(ll i=a;i>=b;--i)
#define lpv(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)
#define test() int t; scanf("%d",&t); while(t--)


using namespace std;
typedef long long int ll;
const int N =(int) 1e3+4;


int main()
{
	string s;
	cin >> s;
	int l = s.length();
	vii dp(4,-1);
	lpi(i,0,l-1)
	{
		if(s[i]=='1')
		{
			if(dp[0] == -1)
				dp[0]=1;
			else
				dp[0] = dp[0]+1;
		}
		else if(s[i]=='8')
		{	
			if(dp[0] == -1)
				continue;
			if(dp[1] == -1)
				dp[1] = dp[0]+1;
			else
				dp[1] = max(dp[1],dp[0])+1;
		}
		else if(s[i]=='0')
		{
			if(dp[1] == -1)
				continue;
			if(dp[2] == -1)
				dp[2] = dp[1]+1;
			else
				dp[2] = max(dp[2],dp[1])+1;	
		}
		else if(s[i]=='7')
		{
			if(dp[2] == -1)
				continue;
			if(dp[3] == -1)
				dp[3] = dp[2]+1;
			else
				dp[3] = max(dp[3],dp[2])+1;
		}
	}
	if(dp[3] == -1)
		cout << 0;
	else
		cout << dp[3];
	return 0;
}