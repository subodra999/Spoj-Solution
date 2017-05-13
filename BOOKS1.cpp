#include<bits/stdc++.h>

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
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		int book[n];
		int total =0;
		lpi(i,0,n-1)
		{
			cin >> book[i];
			total += book[i];
		}	
		
		int lo,hi=total;
		lo = *max_element(book,book+n);
		while(lo<hi)
		{
			int mid = lo+(hi-lo)/2;
			int check=0,scriber=1;
			lpi(i,0,n-1)
			{
				if(check+book[i] <= mid)
				{
					check += book[i];
				}
				else
				{
					scriber++;
					check = book[i];
				}
			}
			if(scriber <= k)
			{
				hi = mid;
			}
			else
			{
				lo = mid+1;
			}
		}
		int ans = lo;
		vii slash(n,false);
		int s = 0;
		k--;
		for(int i=n-1;i>=0;--i)
		{
			if(s+book[i] <= ans && (i >= k))
			{
				s+=book[i];
			}
			else
			{
				slash[i]=true;
				k--;
				s=book[i];
			}
		}
		for(int i=0;i<n;i++)
		{
			cout << book[i] << " ";
			if(slash[i])
				cout << "/ ";
		}
		cout << endl;
	}
	return 0;
}
