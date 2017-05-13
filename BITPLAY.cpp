#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,k;
	ll n,ans,bit;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		int c = __builtin_popcount(n);
		int m = min(c,k);
		int cl = c-(m-1);
		ans = 1;
		bit = 2;
		while(bit<=n)
		{
			if(bit&n)
			{
				cl--;
				if(cl<=0)
					ans|=bit;
			}
		}
		cout << ans << endl;
	}
}