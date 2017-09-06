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
	int n,m;
	cin >> n >> m;

	int t,mx,my,c1x,c2x,c1y,c2y;
	cin >> t;
	while(t--)
	{
		cin >> mx >> my >> c1x >> c1y >> c2x >> c2y;
		int cnt1=0, cnt2=0, cnt3=0, cnt4=0;
		//up
		if(c1y>=my)
		{
			if(c1y-my<=abs(mx-c1x))
			{
				cnt1++;
			}
		}
		if(c2y>=my)
		{
			if(c2y-my<=abs(mx-c2x))
			{
				cnt1++;
			}
		}
		//down
		if(c1y<=my)
		{
			if(my-c1y<=abs(mx-c1x))
			{
				cnt2++;
			}
		}
		if(c2y<=my)
		{
			if(my-c2y<=abs(mx-c2x))
			{
				cnt2++;
			}
		}
		//left
		if(c1x<=mx)
		{
			if(mx-c1x<=abs(my-c1y))
			{
				cnt3++;
			}
		}
		if(c2x<=mx)
		{
			if(mx-c2x<=abs(my-c2y))
			{
				cnt3++;
			}
		}
		//right
		if(c1x>=mx)
		{
			if(c1x-mx<=abs(my-c1y))
			{
				cnt4++;
			}
		}
		if(c2x>=mx)
		{
			if(c2x-mx<=abs(my-c2y))
			{
				cnt4++;
			}
		}

		if(cnt1>=1 && cnt2>=1 && cnt3>=1 && cnt4>=1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}