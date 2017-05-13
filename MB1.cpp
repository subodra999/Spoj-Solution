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
vb prime(1000000,true);

vii pal,ans;
bool palindrome(int i)
{
	vii v;
	while(i)
	{
		v.pb(i%10);
		i/=10;
	}
	int j = v.size()-1;
	while(i<j)
	{
		if(v[i++]!=v[j--])
			return false;
	}
	return true;
}
void seive()
{
	prime[0]=prime[1] = false;
	for(int i=2;i*i<1000000;++i)
	{
		if(prime[i])
		{
			for(int j=i*2;j<1000000;j+=i)
			{
				prime[j] = false;
			}
		}
	}
	lpi(i,2,1000000-1)
	{
		if(prime[i])
		{
			ans.pb(i);
			if(palindrome(i))
				pal.pb(i);
		}
	}
}
int len(int n)
{
	int i=1;
	while(n)
	{
		if(n%10)
			i*=(n%10);
		n/=10;
	}
	return i;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	seive();
	int t,n,p;
	vii::iterator it1,it2;
	cin >> t;
	while(t--)
	{
		cin >> n;
		n--;
		it1 = pal.begin() + n;
		int s = len(*it1);
		s--;
		it2 = ans.begin() + s;
		cout << *it1 << " " << *it2 << endl;
	}
	return 0;
}
