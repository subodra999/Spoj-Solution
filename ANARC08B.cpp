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
	map<string,int> c;
	c["063"] = 0;
	c["010"] = 1;
	c["093"] = 2;
	c["079"] = 3;
	c["106"] = 4;
	c["103"] = 5;
	c["119"] = 6;
	c["011"] = 7;
	c["127"] = 8;
	c["107"] = 9;
	
	map<int,string> cc;
	cc[0] = "063";
	cc[1] = "010";
	cc[2] = "093";
	cc[3] = "079";
	cc[4] = "106";
	cc[5] = "103";
	cc[6] = "119";
	cc[7] = "011";
	cc[8] = "127";
	cc[9] = "107";

	while(1)
	{
		string s;
		cin >> s;
		if(s == "BYE")
			return 0;
		int l = s.length();
		string ans = "";
		int i=0;
		lli num=0,num1=0;
		while(i<l)
		{
			if(s[i] == '+')
			{
				num1 = num;
				num = 0;
				i++;
			}
			else if(s[i] == '=')
			{
				i++;
				num += num1;
				if(num == 0)
				{
					ans = cc[0];
				}
				while(num)
				{
					int k = num%10;
					num/=10;
					ans = cc[k]+ans;
				}
			}
			else
			{
				string a = "aaa";
				a[0] = s[i++];
				a[1] = s[i++];
				a[2] = s[i++];
				num = num*10 + c[a];
			}
		}
		cout << s<<ans<<endl;
	}
	return 0;
}
