#include<bits/stdc++.h>
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

using namespace std;

void solve()
{
	vector<pair<int,int> > adj[10002];
	vector<vector<bool> > visit(10002,vector<bool>(10002,true));
	vector<vector<int> > dist(10002,vector<int>(10002,INT_MAX));

	int n,w,m,y,q;
	scanint(n)
	//cin >> n ;
	string s;
	map<string,int> MAP;
	for(int i=1;i<=n;i++)
	{
		cin >> s;
		MAP[s] = i;
	    scanint(m);        //	cin >> m;
		for(int j=0;j<m;j++)
		{
			scanint(y);     scanint(w);		//cin >> y >> w;
			adj[i].push_back(make_pair(w,y));
		}
	}
	for(int i=1;i<=n;i++)
	{
		priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > q;
		q.push(make_pair(0,i));
		pair<int,int> p;
		dist[i][i] = 0;
		while(!q.empty())
		{
			p = q.top();
			q.pop();
			if(visit[i][p.second])
			{
				visit[i][p.second] = false;
				for(vector<pair<int,int> >::iterator it=adj[p.second].begin() ; it!=adj[p.second].end() ; it++)
				{
					if(visit[i][(*it).second])
					{
						if(dist[i][(*it).second] > (dist[i][p.second]+(*it).first))
						{
							dist[i][(*it).second] = dist[i][p.second]+(*it).first;
							q.push(make_pair(dist[i][(*it).second] , (*it).second));
						}
					}
				}
			}
		}
	}
	scanint(q);		//cin >> q;
	string st,en;
	for(int i=0;i<q;i++)
	{
		cin >> st >> en;
		cout << dist[MAP[st]][MAP[en]] << endl;
	}
}
int main()
{
	int t;
	scanint(t);		//cin >> t;
	for(int i=0;i<t;i++)
	{
		solve();
	}
	
}
