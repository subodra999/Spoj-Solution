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
	int t;
	cin >> t;
	while(t--)
	{
		int key;
		cin >> key;
		string s;
		cin >> s;
		int l = s.length();
		int cse,j;
		if(key>=0 && key<=25)
		{
			cse = 1;
		}
		else
		{
			cse = 2;
			key = key%26;
		}
		lpi(i,0,l-1)
		{
			if(s[i] == '.')
				s[i] = ' ';
			else if(s[i]>='a' && s[i]<='z')
			{
				j= s[i]-'a';
				j = (j+key)%26;
				if(cse == 1)
				{
					s[i] = 'a'+j;
				}
				else
				{
					s[i] = 'A'+j;
				}
			}
			else if(s[i]>='A' && s[i]<='Z')
			{
				j = s[i]-'A';
				j = (j+key)%26;
				if(cse == 1)
				{
					s[i] = 'A'+j;
				}
				else
				{
					s[i] = 'a'+j;
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
