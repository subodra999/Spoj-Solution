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

vll cnt(1000001,0);
lli ans[1000001];

void seive()
{
	for(lli i=2;i<=1000000;++i)
	{
			ans[i] += (cnt[i]-1);
			for(lli j=2;i*j<=1000000;++j)	
			{
				ans[i*j] += cnt[i];
			}
	}
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	lli n;
	cin >> n;
	lli ar[n];
	lpl(i,0,n-1)
	{
		cin >> ar[i];
		cnt[ar[i]]++;
	}
	if(cnt[1])
	{
		lpl(i,0,1000000)
			ans[i] = cnt[1];
	}
	ans[0] = cnt[0]-1;
	ans[1] = cnt[1]-1; 
	seive();
	lpl(i,0,n-1)
	{
		cout << ans[ar[i]] << endl;
	}
	return 0;
}
