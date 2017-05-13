#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		long long int ans=0,i=0;
		while(s[i] != '\0')
		{
			ans += (s[i++]-'0');
		}
		cout << ans << endl;
	}
}
