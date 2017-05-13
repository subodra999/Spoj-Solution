#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adj[102];
int dijkstra(int start,int n)
{
	priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > q;
	vector<bool> visit(102,true);
	vector<int> dist(102,INT_MAX);
	q.push(make_pair(0,start));
	pair<int,int> p;
	dist[start] = 0;
	while(!q.empty())
	{
		p = q.top();
		q.pop();
		if(visit[p.second])
		{
			visit[p.second] = false;
			for(vector<pair<int,int> >::iterator it=adj[p.second].begin() ; it!=adj[p.second].end() ; it++)
			{
				if(visit[(*it).second])
				{
					if(dist[(*it).second] > (dist[p.second]+(*it).first))
					{
						dist[(*it).second] = dist[p.second]+(*it).first;
						q.push(make_pair(dist[(*it).second] , (*it).second));
					}
				}
			}
		}
	}
	return dist[n];
}
int main()
{
	int n,m,x,y,w,start,t;
	cin >> n >> start >> t >> m;
	for(int i=0;i<m;i++)
	{
		cin >> x >> y >> w;
		adj[x].push_back(make_pair(w,y));    //pair : ( weight , vertex )
	}
	int cnt=0;
	
	for(int i=1;i<=n;i++)
	{
		if(dijkstra(i,start)<=t)
			cnt++;
	}
	cout << cnt;
}
