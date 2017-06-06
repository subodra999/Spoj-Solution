#include<iostream>

#include<cstring>

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0); 
	//cout << "hello";
	int t;
	cin >> t;
	while(t--)
	{
		int n,a;
		std::cin >> n;
		short int dp[n+1][2];
		memset(dp,0,sizeof(dp));
	
		int k=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cin >> a;
				dp[j][k] = max(dp[j-1][1-k]+a,dp[j][1-k]+a);
				ans = max(ans,dp[j][k]);
			}
			
			k = 1-k;
		}
		std::cout << ans << endl;
	}
	return 0;
}
