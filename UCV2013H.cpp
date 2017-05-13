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
vii g[100001];
vector<bool> visit(100001,true);       //true means we can visit...
int cnt = 0;                           //global value to store no. of connected vertices every time ... 
void dfs(int n)
    {
    if(visit[n])
        {
        cnt++;
        visit[n] = false;
        tr(g[n],it)
            dfs(*it);
    }
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(1)
	{
	int r,c;
    cin >> r >> c;
    vii v;
    int n=r*c;
    if(n==0)
    	return 0;
    lpi(i,1,n)
    	g[i].clear();
    int ar[r][c];
    lpi(i,0,r-1)
    {
    	lpi(j,0,c-1)
    		cin >> ar[i][j];
    }
    int k=0;
   	lpi(i,0,r-1)
    {
    	lpi(j,0,c-1)
    	{
    		k++;
    	
    		visit[k] = true;
    		if(ar[i][j] == 1)
    		{
    				v.pb(k);
    			if((i-1)>-1)
    			{
    				if(ar[i-1][j] == 1)
    					g[k].pb(k-r);
    			}
    			if((i+1)<r)
    			{
    				if(ar[i+1][j] == 1)
    					g[k].pb(k+r);
    			}
    			if((j-1)>-1)
    			{
    				if(ar[i][j-1] == 1)
    					g[k].pb(k-1);
    				
    			}
    			if((j+1)<c)
    			{
    				if(ar[i][j+1] == 1)
    					g[k].pb(k+1);
    			}
    		}
    	}
    }
    mii ans;
    int y=0;
    tr(v,it)
    {
        if(visit[*it])
        {
            cnt=0;
            dfs(*it);
            ans[cnt]++;
            y++;
        }
    }
    cout<<y<<endl;
    for(mii::iterator it=ans.begin();it!=ans.end();it++)
    {
       cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;
	}
	return 0;
}
