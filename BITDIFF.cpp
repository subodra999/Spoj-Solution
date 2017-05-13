#include<bits/stdc++.h>
#define mod 10000007
using namespace std;
typedef long long int ll;

int main()
{
	int t;
	scanf("%d",&t);
	for(int k=1 ; k<=t ; ++k)
	{
		int n;
		scanf("%d",&n);
		ll ar[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld",&ar[i]);
		}
		ll ans = 0, one , zero;
		ll bit = 1 ;
		int j=0;
		while(j<32)
		{
			one = 0;
			for (int i = 0; i < n ; ++i)
			{
				if(ar[i]&bit)
					one++;
			}
			zero = n-one;
			ans = (ans + (2*one*zero))%mod;
			bit <<= 1;
			j++;
		}

		printf("Case %d: %lld\n",k,ans);
	}

}