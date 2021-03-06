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

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		ll people;
		cin >> n >> people;
		vll train(n+1);
		train[0]=0;
		lpi(i,1,n)
		{
			cin >> train[i];
			train[i] += train[i-1];
		}
		ll ma=0, num=0;
		train.pb(train[n]+people+1);
		lpi(i,1,n)
		{
			int findd = train[i-1]+people;

			int l=i, r=n+1, idx=-1;
			while(l<=r)
			{
				int mid = (l+r)/2;
				if(train[mid]>findd)
				{
					idx = mid;
					r = mid-1;
				}
				else
				{
					l = mid+1;
				}
			}
			
			idx--;
			int curr = idx-i+1;
			if(curr > ma)
			{
				ma = curr;
				num = train[idx]-train[i-1];
			}
			else if(curr == ma)
			{
				num = min(num, train[idx]-train[i-1]);
			}
		
		}
		cout << num << " " << ma << endl;
		
		
	}
	return 0;
}