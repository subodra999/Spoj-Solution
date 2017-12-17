#define speed ios::sync_with_stdio(false)
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<cstring>

#define int long long
#define double long double
#define mod 1000000007
#define nax 1000005
#define inf 100000000000000000LL
#define pb push_back
#define mp make_pair
#define in insert
#define ff first
#define ss second
#define pii pair<int,int>
#define vii vector<int>
#define sii set<int>
#define vb vector<bool>
#define mii map<int,int>
#define mis map<int,string>
#define all(n) n.begin(),n.end()
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define lpi(i,a,b) for(int i=a;i<=b;i++)
#define lpir(i,a,b) for(int i=a;i>=b;i--)
#define test() int t; cin >> t; while(t--)

using namespace std;
int ar[50003], st[16][50004];
#undef int
int main(void)
#define int long long
{
	int n,m;
	int l,r;
	cin >> n >> m;
	int MAXN = (int)log2(n);

	lpi(i,0,n-1)
		cin >> ar[i];
	lpi(i,0,n-1)
		st[0][i] = ar[i];
	lpi(i,1,MAXN)
	{
		for(int j=0;j+(1<<i)<=n;j++)
		{
			st[i][j] = max(st[i-1][j] , st[i-1][j+(1<<(i-1))]);
		}
	}
	//	lpi(i,0,n-1)
	//	cout << ar[i] << " ";
	//	cout << endl;
	int ans=0;
	while(m--)
	{
		cin >> l >> r;
		l--,r--;
		if(r-l < 2)
		{
			ans++;
			continue;
		}
		int A = ar[l];
		int B = ar[r];
		r--,l++;
		int len = (r-l)+1;
		int i = (int)log2(len);
		int check = max(st[i][l] , st[i][r-(1<<i)+1]);
	//	cout << A << " " << l << " " << r << " " << check << endl;
		if(check > A)
			continue;
		ans++; 
	}
	cout << ans;
	
	return 0;
}