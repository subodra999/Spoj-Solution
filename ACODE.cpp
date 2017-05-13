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

int value(char a,char b)
{
	int f = a-'0';
	int s = b-'0';
	return (f*10+s);
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	while(1)
	{
		string s;
		cin >> s;
		if(s == "0")
			return 0;
		int l = s.length();
		lli T[l];
		if(s[0] == '0')
		{
			cout << 0 << endl;
			continue;
		}
		T[0] = 1;
		if(l > 1)
		{
			if(s[1] == '0')
			{
				if(s[0] == '1' || s[0] == '2')
					T[1] = 1;
				else
				{
					cout << 0 << endl;
					continue;
				}
			}
			else if(value(s[0],s[1]) <= 26)
				T[1] = 2;
			else
				T[1] = T[0];
		}
		int f=1;
		lpi(i,2,l-1)
		{
			if(s[i] == '0')
			{
				if(s[i-1] == '1' || s[i-1] == '2')
				{
					T[i] = T[i-2];
				}
				else
				{
					cout << 0 << endl;
					f=0;
					break;
				}
			}
			else if(value(s[i-1],s[i])>= 10 && value(s[i-1],s[i]) <= 26)
				T[i] = T[i-1]+T[i-2];
			else
				T[i] = T[i-1];
		}
		if(f)
		cout << T[l-1] << endl;
	}

	return 0;
}
