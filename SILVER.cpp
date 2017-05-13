#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0)
			return 0;
		double ans = log2(n);
		cout << (long long)ans << endl;
	}
}