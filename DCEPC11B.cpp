#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,p,d,l,m;

void extendedeuclid(ll a,ll b)
{
	ll temp;
	if(b==0)
	{
		d = a;
		l = 1;
		m = 0;
	}
	else
	{
		extendedeuclid(b,a%b);
		temp = l;
		l = m;
		m = temp - (a/b)*m;
	}
}

ll inverse(ll a,ll b)
{
	extendedeuclid(a,b);
	return (l%b + b)%b;
}
int main()
{
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--)
	{
		cin >> n >> p;
		if(n >= p)
			cout << "0" << endl;
		else
		{
			ll ans = p-1;
			for(ll i=p-1; i>n; --i)
			{
				ans =(ans * inverse(i,p)) %p;
			}
			cout << ans << endl;
		}
	}
}
