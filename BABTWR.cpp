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

struct node
{
	int l,b,h;
};

vector<node> v;
int ar[3];

void build()
{
	node a;
	lpi(i,0,2)
	{
		a.l = ar[(0+i)%3];
		a.b = ar[(1+i)%3];
		a.h = ar[(2+i)%3];
		if(a.l > a.b)
		{
			int temp = a.l;
			a.l = a.b;
			a.b = temp;
		}
		v.pb(a);
	}
}

bool cmp(node x, node y)
{
	if(x.l*x.b == y.l*y.b)
		return x.h > y.h;
	return x.l*x.b > y.l*y.b;
}

int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if(n==0)
			return 0;
		v.clear();
		while(n--)
		{
			cin >> ar[0] >> ar[1] >> ar[2];
			build();
		}
		sort(all(v), cmp);
		int maxi[v.size()];
		lpi(i,0,v.size()-1)
		{
			maxi[i] = v[i].h;
		}
		lpi(i,1,v.size()-1)
		{
			lpi(j,0,i-1)
			{
				if(v[j].l > v[i].l && v[j].b > v[i].b)
				{
					if(maxi[i] < maxi[j]+v[i].h)
					{
						maxi[i] = maxi[j]+v[i].h;
					}
				}
			}
		}
		int ans = 0;
		lpi(i,0,v.size()-1)
		{
			//cout << v[i].l << " " << v[i].b << " " << v[i].h << endl;
			//cout << maxi[i] << endl;
			ans = max(ans, maxi[i]);
		}
		cout << ans << endl;
	}
	
	return 0;
}