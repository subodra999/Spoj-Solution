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


bool prime[7994];
sii p,v;
int dp[7994][4];
void seive()
{
	prime[0] = prime[1] = true;
	for(int i=2;i*i<7994;++i)
	{
		if(!prime[i])
		{
			for(int j=2*i; j<7994; j+=i)
			{
				prime[j] = true;
			}
		}
	}
	for(int i=2;i<7994;++i)
	{
		if(!prime[i])
			p.in(i);
	}
}
bool square_num(int n)
{
	int p = (int)sqrt(n);
	return p*p == n;
}
void init()
{
	int l = p.size();
	for(int i=1;i<=90;++i)
	{
		tr(p,it)
		{
			if(*it < i*i)
				continue;
			bool check = square_num(*it - i*i);
			if(check)
				v.in(*it);
		}
	}
}
int count(int idx,int n)
{
    int i, j, x, y, m=4;
    int s[] = {1,2,3,4};
    int table[n+1][4];
    for (i=0; i<m; i++)
        table[0][i] = 1; 
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i-s[j] >= 0)? table[i - s[j]][j]: 0;
            y = (j >= 1)? table[i][j-1]: 0;
            table[i][j] = x + y;
        }
    }
    lpi(i,0,3)
    {
    	dp[idx][i] = table[n][i];
    }
}
int main()
{
	int t,n,k;
	cin >> t;
	seive();
	init();
	int cnt=0;
	tr(v,it)
	{
		count(cnt,*it);
		cnt++;
	}
	while(t--)
	{
		cin >> n >> k;
		cout << dp[n-1][k-1] << endl;
	}
	
	return 0;
}