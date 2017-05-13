#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
	string pat , text;
	cin >> pat >> text;
	
//Pre-calculated array .... 
	int l = pat.length();
	int i=1 , j=0;
	int pre[l+1];
	pre[0] = 0;
	while(i<l)
	{
		if(pat[i] == pat[j])
		{
			pre[i] = j+1;
			i++;
			j++;
		}
		else
		{
			if(j != 0)
				j = pre[j-1];
			else
			{
				pre[i] = 0;
				i++;
			}
		
		}
	}
	int ans=0;
//String matching ....
	int len = text.length();
	j = 0;
	for (int i = 0; i < len && j < l; )
	{
		if(pat[j] == text[i])
		{
			j++;
			i++;
			if(j == l)
			{
				cout << (i-l) << endl;
				ans++;
				j = pre[j-1];	
			}
		}	
		else{
			if(j != 0)
				j = pre[j-1];
			else
				i++;
		}
	}
	
        if(ans == 0)
    		cout << endl;
    }
	return 0;
}