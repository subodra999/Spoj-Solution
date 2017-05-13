#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adj[100002];
vector<bool> visit(100002,true);
vector<int> dist(100002,INT_MAX);
void dijkstra(int start)
{
	priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > q;
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
}
int main()
{
	int start,q,m,x,y,w;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		cin >> x >> y >> w;
		adj[x].push_back(make_pair(w,y));    //pair : ( weight , vertex )
		adj[y].push_back(make_pair(w,x));
	}
	cin >> start;
	dijkstra(start);
	while(q--)
	{
		cin >> x;
		if(!visit[x])
		{
			cout << dist[x] << endl;
		}
		else
		{
			cout << "NO PATH" << endl;
		}
	}
	
}
