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

using namespace std;
typedef long long int ll;

ll dp[1005][1005];
ll ar[1005];
int recur(int str,int en)
{
	if(str>en)
		return 0;
	int str1,str2,end1,end2;
	if(ar[str+1]>=ar[en])
		str1 = str+2, end1 = en;
	else
		str1 = str+1, end1 = en-1;

	if(ar[str]>=ar[en-1])
		str2 = str+1, end2 = en-1;
	else
		str2 = str, end2 = en-2;
		
	int t1,t2;
	if(dp[str1][end1] == 0)
		t1 = recur(str1,end1);
	else
		t1 = dp[str1][end1];
	
	if(dp[str2][end2] == 0)
		t2 = recur(str2,end2);
	else
		t2 = dp[str2][end2];
	return dp[str][en] =  max(ar[str]+t1, ar[en]+t2);
}

int main()
{
	int n;
	int t=0;
	while(1)
	{
		cin >> n;
		ll sum=0;
		lpi(i,0,n-1)
		{
			cin >> ar[i];
			sum += ar[i];
		}
		if(n == 0)
			return 0;
		memset(dp,0LL,sizeof(dp));
		ll ans = recur(0,n-1);
		t++;
		cout << "In game "<<t<<", the greedy strategy might lose by as many as "<<2*ans-sum<<" points." << endl;
	}
	return 0;
}