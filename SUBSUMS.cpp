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

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	ll n;
	cin >> n;
	ll a,b;
	cin >> a >> b;
	ll ar[n];
	lpi(i,0,n-1)
		cin >> ar[i];
	ll l1 = n/2;
	ll l2 = n-l1;
	ll ll1 = 1<<l1;
	ll ll2 = 1<<l2;
	vll v1,v2;
	lpi(i,0,ll1-1)
	{
		ll j=1,k=0;
		ll sum=0;
		while(j<=i)
		{
			if(i&j)
			{
				sum += ar[k];
			}
			j<<=1;
			k++;
		}
		v1.pb(sum);
	}
	lpi(i,0,ll2-1)
	{
		ll j=1,k=0;
		ll sum=0;
		while(j<=i)
		{
			if(j&i)
			{
				sum += ar[k+l1];
			}
			j<<=1;
			k++;
		}
		v2.pb(sum);
	}
	sort(all(v2));
	unsigned long long int ans=0;
	vll::iterator low,high;
	for(int i=0;i<v1.size();i++)
	{
		low=lower_bound(v2.begin(),v2.end(),a-v1[i]);
		high=upper_bound(v2.begin(),v2.end(),b-v1[i]);
		ans+=(high-v2.begin())-(low-v2.begin());
	}
	cout<<ans<<endl;

	
	return 0;
}