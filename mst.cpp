#include <bits/stdc++.h>
using namespace std;
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
	int t;
	cin >> t;
	while(t--)
	{	
		cin >> n >> e;
		int milk[n+1];
		for(int i=1;i<=n;i++)
			cin >> milk[i];
	    init();
	    edge.clear();
	    for(int i=0;i<e;i++)
	    {
	    	node a;
	    	cin >> a.x >> a.y >> a.w ;
	    	edge.push_back(a);
	    }
	    sort(edge.begin(),edge.end());
	    int ans= 0;
	    for(int i=0;i<e;i++)
	    {
	    	if(uniono(edge[i].x , edge[i].y))
	    	{
	    		if(milk[edge[i].x]==1 && milk[edge[i].y]==1)
	    			continue;
				ans += edge[i].w;
			}
	   	}
	   	cout << ans;
	}
    return 0;
}

