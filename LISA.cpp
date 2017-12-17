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

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int l = s.length();
		int j=0,k=0;
		vii ar(60), oper(60);
		vector<vii> dp(60,vector<int>(60,0));
		vector<vii> dp2(60,vector<int>(60,0));
		lpi(i,0,l-1)
		{
			if(i%2 == 0)        //number
			{
				dp[j][j] = s[i]-'0';
				dp2[j][j] = s[i]-'0';
				ar[j++] = s[i]-'0';
			}
			else
			{
				if(s[i] == '*')   //multiply
					oper[k++] = 1;
				else             //summation
					oper[k++] = 2;
			}
		}
		int n=j;
		lpi(i,0,n-2)
		{
			if(oper[i] == 1)
			{
				dp[i][i+1] = ar[i]*ar[i+1];
				dp2[i][i+1] = dp[i][i+1];
			}
			else
			{
				dp[i][i+1] = ar[i]+ar[i+1];
				dp2[i][i+1] = dp[i][i+1];
			}
		}
		lpi(i,3,n)
		{
			lpi(j,0,n-i)   //start
			{
				ll temp = inf, smoke, temp2=0;
				int lim = j+i-1;
				lpi(k,j,lim-1)
				{
					ll x,y;
					if(oper[k] == 1)
					{
						x = dp[j][k]*dp[k+1][lim];
					}
					else
					{
						x = dp[j][k]+dp[k+1][lim];
					}
					if(oper[k] == 1)
					{
						y = dp2[j][k]*dp2[k+1][lim];
					}
					else
					{
						y = dp2[j][k]+dp2[k+1][lim];
					}
					if(x < temp)
					{
						temp = x;
					}
					if(y > temp2)
					{
						temp2 = y;
					}
				}
				dp[j][lim] = temp;
				dp2[j][lim] = temp2;
			}
		}
		/*lpi(i,0,n-1)
		{
			lpi(j,0,n-1)
			{
				cout << dp2[i][j] << " ";
			}
			cout << endl;
		}*/
		cout << dp2[0][n-1] << " " << dp[0][n-1] << endl;
	}
	return 0;
}