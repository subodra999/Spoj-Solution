#include<iostream>
#include<cmath>
#include<stack>
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
	int tc=1;
	while(1)
	{
		string s;
		cin >> s;
		if(s[0] == '-')
			return 0;
		stack<char> q;
		int l = s.length();
		int ans = 0;
		lpi(i,0,l-1)
		{
			if(s[i] == '{')
				q.push(s[i]);
			else
			{
				if(q.empty())
				{
					ans++;
					q.push('{');
				}
				else
					q.pop();
			}
		}
		ans += (q.size()/2);
		cout <<tc << ". "<< ans << endl;
		tc++;
	}

	return 0;
}
