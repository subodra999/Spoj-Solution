#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	long long g1,g2,g3,p;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>g1>>g2>>g3;
		long long n,d,a;
		n=(2*g3)/(g1+g2);
		d=(2*g3-2*n*g1)/(n*n-5*n);
		cout<<n<<endl;
		a=g1-2*d;
		for(int j=1;j<=n;j++)
		{
			p=a+(j-1)*d;
			cout<<p<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}