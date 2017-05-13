#include <stdio.h>
int rev(int n)
{int m=0,r;
	while(n!=0)
  {
     r=n%10;
     m=m*10+r;
     n/=10;
  }
	return m;
}

int main(void) 
{
	int t,a,b,i,n;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{scanf("%d %d ", &a,&b);
	n=rev(a)+rev(b);
	while(n%10==0)
	n=n/10;
	
	printf("%d\n", rev(n));
	}
}

	
