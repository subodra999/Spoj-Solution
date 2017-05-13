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

struct node{
	int w;
	int x;
	int y;
	bool operator < (const node& p) const { 
            if(w < p.w) return true; 
            return false; 
       } 
};
vector<node> edge;
int n,e;
int id[100001];
void init()
{
	for(int i=1;i<=n;i++)
		id[i]= i;
}
int root(int idx)
{
	if(id[idx] == idx)
		return idx;
	id[idx] = root(id[idx]);
	return id[idx];
}
bool uniono(int a,int b)
{
 	int root_a = root(a);
 	int root_b = root(b);
	if(root_a != root_b) 
	{
		id[root_a] = root_b;
		return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	int t;
	cin >> t;
	while(t--)
	{
		
		int m,j,k;
		string s;
		cin >> n;
		init();
		lpi(i,1,n)
		{
			cin >> s;
			cin >> m;
			lpi(p,1,m)
			{
				cin >> j >> k;
				node a;
				a.x = i;
				a.y = j;
				a.w = k;
				edge.pb(a);
			}
		}
		sort(all(edge));
	    int ans= 0;
	    e = edge.size();
	  //  cout <<"e : " << e << endl;
	    for(int i=0;i<e;i++)
	    {
	    	
			//cout << edge[i].x <<" "<<edge[i].y <<" "<< edge[i].w <<endl;
	    	if(uniono(edge[i].x , edge[i].y))
	    	{
	    		ans+= edge[i].w;
			}
	   	}
	   	edge.clear();
	   	cout << ans << endl;
		
	}
	return 0;
}
