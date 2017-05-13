#include <bits/stdc++.h>

#define lli long long int
using namespace std;
vector<lli> v;
void init()
{
	v.push_back(1);
	v.push_back(1);
	lli i = 2;
	while((v[i-1] + v[i-2]) <= 1000000000 )
	{
		v.push_back(v[i-1] + v[i-2]);
		i++;
	}
}
lli fibo(lli n)
{
	return v[n+1];	
}
int main() {
	lli t,n,ans,l,r;
	cin >> t;
	init();
	while(t--)
	{
		cin >> n;
		cout << fibo(n) << endl;
	}
	return 0;
}