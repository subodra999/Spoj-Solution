#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

int m = pow(10,9) + 7;
int x[1500][1500];

int mx(int a,int b)
{
	return a>b?a:b;
}

int ans(int h,int a)
{
	if(h<=0 || a<=0)
	{
		return 0;
	}
	if(x[h][a]!=-1)
	{
		return x[h][a];
	}
	else
	{
		x[h][a] = mx(1 + ans(h+3-5,a+2-10),1 + ans(h+3-20,a+2+5));
	}
	return x[h][a];	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(x,-1,sizeof(x));
		int h,a;
		cin>>h>>a;
		cout<<2*ans(h,a)-1<<endl;
	}
	return 0;
}