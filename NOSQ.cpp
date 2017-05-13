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
#define sll set<long long int>
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mis map<int,string>
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define lpi(i,a,b) for(int i=a;i<=b;i++)
#define lpir(i,a,b) for(int i=a;i>=b;i--)
#define lpl(i,a,b) for(lli i=a;i<=b;++i)
#define lplr(i,a,b) for(lli i=a;i>=b;--i)
#define lpv(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)

using namespace std;

typedef unsigned long long int ull;
typedef long long int lli;
typedef vector<vector<lli> > mat;

void swap(lli *a,lli *b) { lli t=*a;  *b=*a, *a=t; }
bool isOdd(lli n){ if(n&1) return 1; return 0; }
lli noSetBit(lli n){ lli cnt=0; while(n){ n&=(n-1); cnt++;} return cnt; }
bool isSquare(lli n) { double d = sqrt(n); if(d==(lli)d) return 1; return 0;}
int level[100001];
void init()
{
	lpi(i,0,100000)
	{
		int j=i , cnt=0;
		while(j%2 == 0)
		{
			cnt++;
			j/=2;
		}
		if(cnt!=0 && cnt%2 == 0)
		{
			level[i] = 0;
			continue;
		}
		int f=1;
		for(int k=3;k<=j;k+=2)
		{
			cnt =0;
			while(j%k == 0)
			{
				j/=k;
				cnt++;
			}
			if(cnt!=0 && cnt%2 == 0)
			{
				level[i] = 0;
				f=0;
				break;
			}
		}
		if(f)
			level[i] = 1;
	
	/*
		int f=1;
		for(int j=1; j*j<=i; j++)
		{
			if(i%j == 0)
			{
				if(j!=1 && isSquare(j))
				{
					level[i] = 0;
					f=0;
					break;
				}
				if(j != i/j)
				{
					if(isSquare(i/j))
					{
						level[i] = 0;
						f=0;
						break;
					}
				}
			}
		}
		if(f)
			level[i] = 1;*/
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	init();
	int t;
	cin >> t;
	int a,b,d;
	while(t--)
	{
		cin >> a >> b >> d;
		int cnt=0;
		lpi(i,a,b)
		{
			if(level[i])
			{
				int j=i;
				while(j)
				{
					
					if(j%10 == d)
					{
						cnt++;
						j=0;
					}
					j/=10;
				}
				
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
