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
vii m[65];
vector<bool> visit(65,true) ;
vii level(65,0);
void init()
{
	char r='1' , c='a';
	for(char i=r;i<='8';i++)
	{
		for(char j=c;j<='h';j++)
		{
			int s = 8*(j-'a')+(i-'0');
            char i2 = i+2 , ii2 = i-2 , i1 = i+1 , ii1 = i-1;
            char j2 = j+2 , jj2 = j-2 , j1 = j+1 , jj1 = j-1;
			if(i2<='8' && j1<='h')
			{
				m[s].push_back(s+2+8);
			}
            if(ii2>='1' && j1<='h')
			{
				m[s].push_back(s-2+8);
			}
			if(i2<='8' && jj1>='a')
			{
				m[s].push_back(s+2-8);
			}
			if(ii2>='1' && jj1>='a')
			{
				m[s].push_back(s-2-8);
			}
			if(i1<='8' && j2<='h')
			{
				m[s].push_back(s+1+16);
			}
			if(ii1>='1' && j2<='h')
			{
				m[s].push_back(s-1+16);
			}
			if(i1<='8' && jj2>='a')
			{
				m[s].push_back(s+1-16);
			}
			if(ii1>='1' && jj2>='a')
			{
				m[s].push_back(s-1-16);
			}
		}
	}
}
void bfs(int n,int d)
    {
    queue<int> q;
    q.push(n);
    level[n] = 0;
    visit[n] = false;
    while(!q.empty())
        {
        int p = q.front();
       // cout << p << "*";
       // cout << level[p] << endl;
        q.pop();
        if(p == d)
            {
            cout << level[p] << endl;
            return;
        }
        for(vii::iterator it=m[p].begin() ; it!=m[p].end() ; it++)
            {
            if(visit[*it])
           	{
                q.push(*it);
                visit[*it] = false;
                level[*it] = level[p]+1;
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); 
	init();
    int t ;
    char r='0' , c='a';
    cin >> t;
    while(t--)
    {
        lpi(i,1,64)
        {
            visit[i] = true;
            level[i] = 0;
        }   
        
        string ini,fin;
        cin >> ini >> fin;
        int start = 8*(ini[0]-c) + (ini[1]-r);
        int destn = 8*(fin[0]-c) + (fin[1]-r);
        bfs(start,destn);
    }

	return 0;
}
