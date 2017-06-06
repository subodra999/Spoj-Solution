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

bool isTwo(lli n)
{
	int i=0,cnt=0;
	while(n)
	{
		if(n%2 == 1)
			cnt++;
		n/=2;
		i++;
	}
	return i==cnt;
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int t;
	cin >> t;
	while(t--)
	{
		lli n;
		cin >> n;
		int p = log2(n);
		lli ans = n - pow(2,p)+1;
		int l = (int)log2(ans);
		int len = (int)log2(n+1);
		string s(len,'5');
		//cout << s << endl;
		if(isTwo(n))
			cout << s << endl;
		else
		{
			int i=len-1;
			while(ans)
			{
				if(ans%2 == 1)
					s[i] = '6';
				i--;
				ans/=2;
			}
			cout << s << endl;
		}

	}
	return 0;
}
