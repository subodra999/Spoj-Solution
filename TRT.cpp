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

int ar[2001];
vector<vector<int> > T(2001,vector<int>(2001,-1));
int func(int st,int en,int age)
{
	if(st > en)
		return 0;
	if(T[st][en] != -1)
		return T[st][en];
	return T[st][en]= max(func(st+1,en,age+1)+ar[st]*age , func(st,en-1,age+1)+ar[en]*age);
}
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	int n;
	cin >> n;
	lpi(i,1,n)
	{
		cin >> ar[i];
	}
	int ans = func(1,n,1);
	cout << ans;
	return 0;
}
