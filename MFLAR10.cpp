#include <iostream>
using namespace std;

int main() {
	// your code goes here
	while(1)
	{
		string s;
		getline(cin,s);
		if(s == "*")
			return 0;
		int l = s.length();
		int check1,check2;
		
		if(s[0] >= 65 && s[0]<=90)
		{
			check1 = s[0];
			check2 = s[0]+32;
		}
		else
		{
			check1 = s[0]-32;
			check2 = s[0];
		}
		int f=1;
		for(int i=1;i<l;i++)
		{
			if(s[i] == ' ')
			{
				if(s[i+1] == check1 || s[i+1] == check2)
				{
					i++;
				}
				else
				{
					f = 0;
					break;
				}
			}
		}
		if(f)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
	return 0;
}