#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<cstring>

#define ll long long int
#define lb long double
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define in insert
#define ff first
#define ss second
#define lpi(i,a,b) for(int i=a;i<=b;i++)

using namespace std;

const int N = (int)1e5+5;

int modulo(string num, int a)
{
    int res = 0;
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;
    return res;
}

int gcd(int a,int b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a;
		string num;
		cin >> a >> num;
		if(a == 0)
		{
			cout << num << endl;
			continue;
		}
		int b = modulo(num,a);
		cout << gcd(a,b) << endl;
	}
	return 0;
}