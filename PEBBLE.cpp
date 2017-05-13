#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t=0,l;
	char s[2001];
	while(scanf("%s",s)!=EOF)
	{
		t++;
		l = strlen(s);
		int j=0;
		if(s[0]=='1')
			j++;
		for(int i=1;i<l;++i)
		{
			if(s[i] == s[i-1])
				continue;
			else
				s[j++] = s[i];
		}
		int cnt=0;
		for(int i=0;i<j-1;++i)
		{
			if(s[i] == '1')
				cnt++;
		}
		cnt *= 2;
		if(s[l-1] == '1')
			cnt++;
		printf("Game #%d: %d\n",t,cnt);
		//cout << "Game #"<<i<<": " << cnt << endl;
	}
}