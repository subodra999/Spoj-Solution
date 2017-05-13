#include<bits/stdc++.h>
using namespace std;
vector<int> v(1000005,0);
int pre = 0;
void seive()
{
	v[0] = v[1] = 1;
	for (int i = 2; i*i < 1000001; ++i)
	{
		if(v[i] == 0)
		{
			for (int j = i*2; j <= 1000000; j+=i)
			{
				v[j] = 1;
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	seive();
	for (int k = 1; k <= t; ++k)
	{
		int ans = 0;
		std::vector<int> vi(v);
		int n,no,a;
		scanf("%d %d",&n,&no);
		for (int i = 0; i < no; ++i)
		{
			scanf("%d",&a);
			for (int j = a*2; j <= n; j+=a)
			{
				vi[j] = 0;
			}
		}
		for (int i = 2; i <= n; ++i)
		{
			if(vi[i])
			{
				ans++;
				//cout << i << " ";
			}
		}
		printf("Case %d: %d\n",k,ans );
	}
}