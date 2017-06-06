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
lli fast_exp(lli a,lli b)
{
	if(a==0)
		return 0;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(b%2==0)
	{
		return fast_exp(((a)*(a)),b/2);
	}
	return ((a)*fast_exp(((a)*(a)),(b-1)/2));
}


int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int t=1;
	while(1)
	{
		int n;
		cin >> n;
		if(n == -1)
			return 0;
		cout << "Case "<<t<<":"<<endl;
		t++;
		lli c[n+1];
		lpir(i,n,0)
			cin >> c[i];
		int m;
		lli a;
		cin >> m;
		while(m--)
		{
			cin >> a;
			lli ans = 0;
			lpir(i,n,1)
			{
				ans += (c[i]*fast_exp(a,i));
			}
			ans += c[0];
			cout << ans << endl;
		}
	}
	return 0;
}
