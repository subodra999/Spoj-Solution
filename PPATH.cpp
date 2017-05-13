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
int ans;
vector<bool> prime(100005,true);

vector<int> adj[100005];

void seive()
{
	for(int i=2;i*i<100000;i++)
	{
		if(prime[i])
		{
			for(int j=2*i;j<100000;j+=i)
			{
				prime[j] = false;
			}
		}
	}
}

int number(int a,int b,int c,int d)
{
	int ans = 1000*a + 100*b + 10*c + d;
	return ans;
}

void generate()
{
	lpi(j,1000,9999)
	{
		if(prime[j])
		{
			int num = j;
			int d = num%10;   num/=10;
			int c = num%10;   num/=10;
			int b = num%10;   num/=10;
			int a = num;
			lpi(i,0,9)
			{
				int n = number(a,b,c,i);
				if(prime[n]&&n!=j)
					adj[j].pb(n);
			}
			lpi(i,0,9)
			{
				int n = number(a,b,i,d);
				if(prime[n]&&n!=j)
					adj[j].pb(n);
			}
			lpi(i,0,9)
			{
				int n = number(a,i,c,d);
				if(prime[n]&&n!=j)
					adj[j].pb(n);
			}
			lpi(i,1,9)
			{
				int n = number(i,b,c,d);
				if(prime[n]&&n!=j)
					adj[j].pb(n);
			}
		}
	}
}
int bfs(int num,int dest)
{
	vii level(100005,-1);
	vector<bool> visit(100005,true);
	queue<int> s;
	s.push(num);
	level[num] = 0;
	visit[num] = false;
	while(!s.empty())
	{
		int p = s.front();
		s.pop();
		if(p == dest)
			return level[dest];
		for(vii::iterator it=adj[p].begin();it!=adj[p].end();it++)
		{
			if(visit[*it])
			{
				s.push(*it);
				level[*it] = level[p]+1;
				visit[*it] = false;
				//	cout << *it << " ";	
			}
		}
	//		cout << endl;
	}
	
		return level[dest];
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int t,x,y;
	cin >> t;
	seive();
	generate();
/*	lpi(i,1000,1020)
	{
		cout << i << " : ";
		for(vii::iterator it = adj[i].begin();it!=adj[i].end();it++)
			cout << *it << " ";
		cout << endl;  
	}*/
	while(t--)
	{
		cin >> x >> y;
		int ans = bfs(x,y);
		if(ans != -1)
			cout << ans << endl;
		else 
			cout << "Impossible" << endl;	
	}	
	return 0;
}
