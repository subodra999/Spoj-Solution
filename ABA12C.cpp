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
vector<int> T(1001);
void init(int n)
{
	lpi(i,0,n)
		T[i] = nax;
}
int rec(vector<pii> &coin,int n)
{
	if(n < 0)
		return nax;
	if(n == 0)
		return n;
	if(T[n] != nax)
		return T[n];
	for(vector<pii>::iterator it=coin.begin() ; it!=coin.end() ; ++it)
	{
		T[n] = min(T[n],rec(coin,n-(*it).ff)+(*it).ss);
	}
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int t,a;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		init(k);
		vector<pii> v;
		lpi(i,1,k)
		{
			cin >> a;
			if(a != -1)
				v.pb(mp(i,a));
		}
		rec(v,k);
	//	lpi(i,1,k)
	//		cout << T[i] << " ";
		if(T[k] >= nax)
			cout << "-1" << endl;
		else
			cout << T[k] << endl;
	}
	return 0;
}
