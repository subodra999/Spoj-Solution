#include<bits/stdc++.h>
using namespace std;
int phi(int n)
{
	int ans = n;
	for(int i=2;i*i<=n;++i)
	{
		if(n%i == 0)
		{
			while(n%i == 0)
			{
				n/=i;
			}
			ans -= ans/i;
		}
	}
	if(n>1)
		ans -= ans/n;
	return ans;
}
int main()
{
	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << phi(n) << endl;
	}
}