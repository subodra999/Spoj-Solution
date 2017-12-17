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
#define speed ios::sync_with_stdio(false)

using namespace std;
typedef long long int ll;

string s1,s2;
int dp[85][85];
set<string> SET;

void dp_matrix()
{
	memset(dp,0,sizeof(dp));
	lpi(i,1,s1.length())
	{
		lpi(j,1,s2.length())
		{
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}
}

map<string,bool> processed[81][81]; 

void print(int i,int j,string s)
{
	if(processed[i][j].find(s) != processed[i][j].end())
    	return;
	if(i == 0 || j == 0)
	{
		SET.in(s);
		return;
	}
	if(s1[i-1] == s2[j-1])
	{
		string str = s;
		str = s1[i-1]+str;
		print(i-1,j-1,str);
	}
	else if(dp[i-1][j] > dp[i][j-1])
	{
		print(i-1,j,s);	
	}
	else if(dp[i][j-1] > dp[i-1][j])
	{
		print(i,j-1,s);
	}
	else
	{
		print(i-1,j,s);
		print(i,j-1,s);
	}
	processed[i][j][s] = true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char c_s1[81], c_s2[81];
		scanf("%s\n%s",c_s1,c_s2);
		s1 = c_s1; s2 = c_s2;
		dp_matrix();
		SET.clear();
		lpi(i,0,80)
		{
			lpi(j,0,80)
				processed[i][j].clear();
		}
		print(s1.length(), s2.length(), "");
		tr(SET,it)
		{
			printf("%s\n", it->c_str());
		}
		printf("\n");
	}
	return 0;
}