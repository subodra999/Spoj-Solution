#include <bits/stdc++.h>
using namespace std;
int vis[2001];
vector<int> v[2001];

void dfs(int idx)
{
	if(vis[idx] != 0)
		return;
	vis[idx] = 1;
	
	cout << idx <<" ";
	for(vector<int>::iterator it = v[idx].begin() ; it!=v[idx].end() ; it++)
	{
		dfs(*it);
	}
}
int main() {
	int t , x , y;
	cin >> t;
	while(t--)
	{
		cin >> x >> y;
		v[x].push_back(y);
	}
	dfs(1);
	return 0;
}
