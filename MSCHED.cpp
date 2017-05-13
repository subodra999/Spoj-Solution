#include<bits/stdc++.h>
using namespace std;
class milk
{
	public :
		int m;
		int t;
	bool operator <(const milk& o){
		return this->m > o.m;
	}
};
bool vis[1000005];
int main()
{
	int  ans=0;
	int n;
	cin >> n;
	int mi,ti;
	milk ar[n];
	for(int i=0;i<n;++i)
	{
		cin >> ar[i].m >> ar[i].t;
	}
	sort(ar,ar+n);
	for(int i=0;i<n;i++)
	{
		if(vis[ar[i].t] == false)
		{
			vis[ar[i].t] = true;
			ans += (ar[i].m);
		}
		else
		{
			for(int j=ar[i].t ; j>=1 ; --j)
			{
				if(vis[j] == false)
				{
					ans += (ar[i].m);
					vis[j] = true;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}
