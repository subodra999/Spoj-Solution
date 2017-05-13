#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
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
	
	int t;
	cin >> t;
	while(t--)
	{
		lli h,a;
		cin >> h >> a;
		lli i=1,time=0;
		while(1)
		{
			if(i&1)
			{
				h += 3;
				a += 2;
			}
			else
			{
				if(h-20 <= 0)
				{
					h -= 5;
					a -= 10;
				}
				else
				{
					h -= 20;
					a += 5;
				}
				if(h <= 0 || a <= 0)
				{
					cout << time << endl;
					break;
				}	
			}
			i++;
			time++;
		}
	}
	return 0;
}
