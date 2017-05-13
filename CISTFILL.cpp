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

struct box
{
	double l,area,ht;
};
bool cmp(box a,box b)
{
	if(a.l < b.l)
		return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		double ln,bh;
		cin >> n;
		box ar[n];
		double total=0.00;
		lpi(i,0,n-1)
		{
			cin >> ar[i].l >> ar[i].ht >> ln >> bh ;
			ar[i].area = ln*bh;
			total += (ar[i].area*ar[i].ht);
		}
		double capacity;
		cin >> capacity;
		if(capacity > total)
		{
			cout << "OVERFLOW" << endl;
			continue;
		}
		double lo = 0, hi = 1040000.0;;
		int itr=0;
		while(itr<100)
		{
			itr++;
			double mid = lo + (hi-lo)/2;
			double vol = capacity;
			for(int i=0;i<n;i++)
			{
				double length = mid - ar[i].l;
				if(length>0)
				{
					length = min(length , ar[i].ht);
					vol -= (length*ar[i].area);
					if(vol <= 0)
				    {
					    hi = mid;
				    	break;
				    }
				}
			}
			if(vol > 0)
			{
				lo = mid;
			}
		}
		cout<<fixed<<setprecision(2)<<lo<<endl;
	}
	return 0;
}