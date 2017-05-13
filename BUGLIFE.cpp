#include <bits/stdc++.h>
using namespace std;
int vis[2001] , ar[2001];
vector<int> v[2001];
int c=1,a=0;
void dfs(int idx , int f)
{
	if(vis[idx] != 0)
	{
		if(ar[idx] != f && a==0)
		{
			c = 0;
			a++;
		}
		return;
	}
	vis[idx] = 1;
	ar[idx] = f;
	
	for(vector<int>::iterator it = v[idx].begin() ; it!=v[idx].end() ; it++)
	{
		dfs(*it , 3-f);
	}
}
int main() {
	long int t;
	int  loop , n , x , y;
	
	scanf("%d",&loop);
	
	for(int i = 1 ; i<=loop ; i++)
	{
	c = 1;
	a = 0;
	scanf("%d %ld",&n,&t);
	
	for(int j = 0; j<=n ; j++)
	{
		vis[j] = 0;
		ar[j] = 0;
		v[j].clear();
	}
	while(t--)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int k = 1; k <= n ; k++)
	{
		if(vis[k] == 0)
			dfs(k,1);
	}
	
	if(c)
	printf("Scenario #%d:\nNo suspicious bugs found!\n",i);
	else
	printf("Scenario #%d:\nSuspicious bugs found!\n",i);

	}
	return 0;
}
