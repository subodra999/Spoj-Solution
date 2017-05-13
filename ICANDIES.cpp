#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i=1 ; i<=t ; i++)
	{
		int n,f=1;
		cin >> n;
		int j = 5;
		while(j < n)
		{
			if( (n-j)%3 == 0)
			{
				int ans = (n-j);
				cout << "Case " << i << ": " << ans << endl << endl;
				f = 0;	
				break;
			}
		}
		if(f)
		{
			cout << "Case " << i << ": " << ans << endl << endl;
		}
	}
}