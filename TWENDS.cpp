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

int v[1005];
int T[1005][1005];
int rec(int start , int end)
{
	if(start > end)
		return 0;
	if(T[start][end] != -1)
		return T[start][end];
	else
		return T[start][end] = max(rec(start+1,end-1)+v[start],rec(start+1,end-1)+v[end]);
}
int gre(int start,int end)
{
	if(start > end)
		return 0;
	if(v[start] > v[end])
		return v[start]+gre(start+1,end);
	return v[end]+gre(start,end-1);
}
int main()
{
//	ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0)
			return 0;
		
		lpi(i,0,n-1)
			cin >> v[i];
		memset(T,-1,sizeof(T));
		int ans1 = rec(0,n-1);
		int ans2 = gre(0,n-1);
		cout << ans1 << " " <<  ans2 << endl;
	}

	return 0;
}
