#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int r , c;
		cin >> r >> c;
		int ar[r][c] , dp[r][c];
		for(int i=0 ; i<r ; i++)
		{
			for(int j=0 ; j<c ; j++)
			{
				cin >> ar[i][j];
				dp[i][j]=ar[i][j];
			}
		}
		for(int i=1 ; i<r ; i++)
		{
			for(int j=0 ; j<c ;j++)
			{
				if(j==0)
					dp[i][j] = max( ar[i][j]+dp[i-1][j+1] , ar[i][j]+dp[i-1][j]);
				else if(j==(c-1))
					dp[i][j] = max( ar[i][j]+dp[i-1][j-1] , ar[i][j]+dp[i-1][j]);
				else
					dp[i][j] = max( max( ar[i][j]+dp[i-1][j+1] , ar[i][j]+dp[i-1][j]) , ar[i][j]+dp[i-1][j-1]);;
			}
		}
		int ans = 0;
		for(int i=0 ; i<c ; i++)
		ans = max(ans , dp[r-1][i]);
		cout << ans <<endl;
	}
	return 0;
}
