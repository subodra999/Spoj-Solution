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
	int ar[3],n;
	ar[0] = 1;
	cin >> ar[1] >> ar[2] >> n;
	sort(ar,ar+3);
	int q[n];
	lpi(i,0,n-1)
	{
		cin >> q[i];
	}
	sort(q,q+n);
	int l = q[n-1];
	bool T[l+1];
	T[0] = false;
	T[1] = true;
	lpi(i,2,ar[1]-1)
	{
		if(i&1)
			T[i] = true;
		else
			T[i] = false;
	}
	T[ar[1]] = true;
	lpi(i,ar[1]+1,ar[2]-1)
	{
		if(!T[i-1] || !T[i-ar[1]])
			T[i] = true;
		else
			T[i] = false;
	}
	T[ar[2]] = true;
	lpi(i,ar[2]+1,l)
	{
		if(!T[i-1] || !T[i-ar[1]] || !T[i-ar[2]])
			T[i] = true;
		else
			T[i] = false;
	}

	lpi(i,0,n-1)
	{
		if(T[q[i]])
			cout << "A" ;
		else
			cout << "B" ;
	}
	return 0;
}
