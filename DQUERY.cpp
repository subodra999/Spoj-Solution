//MO's Algorithm implementation...
#include<bits/stdc++.h>
using namespace std;
int s,curr=0;
std::vector<int> v(30005);
std::vector<int> cnt(1000005,0);
std::vector<int> ans(1000005);
struct node
{
	int l,r,ii;
};
bool comp(node n1 , node n2){
    if(n1.l/s < n2.l/s)
        return true;
    else if(n1.l/s == n2.l/s && n1.r < n2.r)
        return true;
    return false;
}
void add(int n)
{
	cnt[n]++;
	if(cnt[n] == 1)
		curr++;
}
void remove(int n)
{
	cnt[n]--;
	if(cnt[n] == 0)
		curr--;
}
int main()
{
	int n;
	scanf("%d",&n);
	s = sqrt(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&v[i]);
	}
	int query;
	scanf("%d",&query);
	node q[query];
	for(int i=0 ; i < query ; ++i)
	{
		scanf("%d %d",&q[i].l , &q[i].r);
		q[i].ii = i;
	}
	sort(q , q+query , comp);
	for(int i=0 ; i < query ; ++i)
	{
		printf("%d %d %d\n",q[i].l , q[i].r , q[i].ii);
	}
	int mo_l=0 , mo_r=-1;
	for (int i = 0; i < query; ++i)
	{
		int ll = q[i].l;
		int rr = q[i].r;
		while(mo_r < rr)
		{
			mo_r++;
			add(v[mo_r]);
		}
		while(mo_l < ll)
		{
			mo_l++;
			remove(v[mo_l-1]);
		}
		while(mo_l > ll)
		{
			mo_l--;
			add(v[mo_l]);
		}
		while(mo_r > rr)
		{ 
			mo_r--;
			remove(v[mo_r+1]);
		}
		ans[q[i].ii] = curr;
	}
	for (int i = 0; i < query; ++i)
	{
		printf("%d\n",ans[i]);
	}
}