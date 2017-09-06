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

bool check(string s, int n)
{
	int l = s.length();
	ll curr=0;
	lpi(i,0,l-1)
	{
		curr*=10;
		curr+=(s[i]-'0');
		curr%=n;
	}
	return curr==0;
}

void init(int n)
{
	string s="1";
	queue<string> q;
	q.push(s);
	while(1)
	{
		string s = q.front();
		if(check(s+'0',n))
		{
			cout << (s+'0') << endl;
			return;
		}
		q.push(s+'0');
		if(check(s+'1',n))
		{
			cout << (s+'1') <<endl;
			return;
		}
		q.push(s+'1');
		q.pop();
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(n==1)
			cout<<1<<endl;
		else
			init(n);
	}
	return 0;
}