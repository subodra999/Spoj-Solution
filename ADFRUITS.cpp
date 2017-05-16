#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>

#define mod 1000000007
#define nax 1000005
#define inf 100000000000000000LL
#define pb push_back
#define mp make_pair
#define in insert
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>
#define vii vector<int>
#define sii set<int>
#define vb vector<bool>
#define sll set<long long int>
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mis map<int,string>
#define all(n) n.begin(),n.end()
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define lpi(i,a,b) for(int i=a;i<=b;i++)
#define lpir(i,a,b) for(int i=a;i>=b;i--)
#define lpl(i,a,b) for(lli i=a;i<=b;++i)
#define lplr(i,a,b) for(lli i=a;i>=b;--i)
#define lpv(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)

using namespace std;
typedef long long int lli;


int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";

	while(1)
	{
	//scanf("%s %s",a,b);
	string a,b;
	cin >> a >> b;
	if(a == "")
	break;
	int la,lb;
	la = a.length();
	lb = b.length();
	vector<vii> T(la+1,vii(lb+1,0));

	a = " "+a;
	b = " "+b;
	lpi(i,0,la)
	{
		lpi(j,0,lb)
		{
			if(i == 0)
                T[i][j] = 0;
            else if(j == 0)
                T[i][j] = 0;
            else if(a[i] == b[j])
                T[i][j] = 1 + T[i - 1][j - 1];
            else
                T[i][j] = max(T[i - 1][j], T[i][j - 1]);
		}
	}
	string str="";
	int i = la, j = lb;
	while (i > 0 && j > 0)
	{
		if (a[i] == b[j])
		{
			str+=(a[i]);
			i--; j--;
		}

		else if (T[i - 1][j] > T[i][j - 1])
		{
			str+=(a[i]);
			i--;
		}
		else
		{
			str+=(b[j]);
			j--;
		}
	}

	while (i > 0)
	{
		str+=(a[i]);
		i--; 
	}
	while (j > 0)
	{
		str+=(b[j]);
		j--;
	}
	int l=str.length();
	l--;
	for(int i=l;i>=0;--i)
		cout << str[i];
	cout << endl;
	}
	return 0;
}
