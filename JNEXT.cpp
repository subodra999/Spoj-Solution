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
		int n;
		cin >> n;
		int ar[n];
		lpi(i,0,n-1)
		{
			cin >> ar[i];
		}
		int i = n-1;
		while(i>0 && ar[i-1]>=ar[i])
		{
			i--;
		}
		if( i==0)
			cout << -1 << endl;
		else
		{
			int j=n-1;
			while(ar[i-1] >= ar[j])
				j--;
			int temp = ar[i-1];
			ar[i-1] = ar[j];
			ar[j] = temp;
			reverse(ar+i,ar+n);
			lpi(i,0,n-1)
				cout << ar[i];
			cout << endl;
		}
	}
	return 0;
}
