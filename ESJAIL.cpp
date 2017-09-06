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
	int n,k,m;
	while(1)
	{
		cin >> n >> k >> m;
		if(n == -1)
			return 0;
		vii adj[n+1];
		int key , door;
		int vis[n+1];
		memset(vis,0,sizeof(vis));
		bool open[n+1], toopen[n+1], v[n+1];
		memset(v,true,sizeof(v));
		memset(open,false,sizeof(open));
		memset(toopen,false,sizeof(toopen));
		lpi(i,0,k-1)
		{
			cin >> key >> door;
			vis[key] = door;
			vis[door] = -1;
		}
		int x,y;
		lpi(i,1,m)
		{
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		queue<int> q;
		q.push(1);
		v[1] = false;
		bool flag = true;
		while(!q.empty())
		{
			int p = q.front();
			q.pop();
			if(p == n)
			{
				cout << "Y" << endl;
				flag = false;
				break;
			}
			tr(adj[p],it)
			{
				if(v[*it])
				{
					if(vis[*it] == -1)
					{
						if(open[*it])
						{
							q.push(*it);
							v[*it] = false;
						}
						else
						{
							toopen[*it] = true;
						}
					}
					else if(vis[*it] == 0)
					{
						q.push(*it);
						v[*it] = false;
					}
					else
					{
						q.push(*it);
						v[*it] = false;
						if(toopen[vis[*it]] && v[vis[*it]])
						{
							q.push(vis[*it]);
							v[vis[*it]] = false;
						}
						else
						{
							open[vis[*it]] = true;
						}

					}
				}
			}
		}
		if(flag)
			cout << "N" << endl;


	}
	
	return 0;
}