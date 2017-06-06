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

struct node
{
	int s,e,p;
};
bool cmp(node a,node b)
{
	if(a.s == b.s)
		return a.e < b.e;
	return a.s < b.s;
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int t;
	cin >> t;
	while(t--)
	{
		int n,l=0;
		cin >> n;
		vector<node> v;
		lpi(i,0,n-1)
		{
			node a;
			cin >> a.s >> a.e >> a.p;
			a.e+=a.s;
			l = max(l,a.e+a.s);
			v.pb(a);
		}
		sort(all(v),cmp);
		vii T(l+1,0);
		int i=0,ans=0,m=0;
		for(vector<node>::iterator it=v.begin() ; it!=v.end() ; )
		{
			while(i <= (*it).s)
			{
				m = max(m,T[i]);
				i++;
			}
			T[(*it).e] = max(T[(*it).e] , m+(*it).p);
			ans = max(ans , T[(*it).e]);
			++it;
		}
		/*for(int i=0;i<=l;++i)
			cout << T[i] << " ";*/
		cout << ans << endl;
	}
	return 0;
}
