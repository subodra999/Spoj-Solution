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


int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int test;
	cin >> test;
	lpi(t,1,test)
	{
		string s;
		cin >> s;
		int l = s.length();
		int one=0,zero=0,f=1;
		lpir(i,l-1,0)
		{
			if(s[i] == '0')
				zero++;
			else
			{
				if(zero >= 2)
					zero -= 2;
				else
				{
					cout << "Case "<< t << ": no" << endl;
					f=0;
					break; 
				}
			}
		}
		if(f)
		{
			if(zero == 0)
				cout << "Case "<< t << ": yes" << endl;
			else
				cout << "Case "<< t << ": no" << endl;
		}
	}
	return 0;
}
