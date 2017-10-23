#include<iostream>
#include<cstring>
using namespace std;
int dp[101][101];
int a[101][101];
int max(int a,int b)
{
	if (a>b) return a;
	return b;
}
int main()
{
	int n;
	int k;
	memset(dp,-1,sizeof(dp));
	cin>>k;
	for (int i=1; i<=k; i++)
	{
		cin>>n;
		for (int i1=1; i1<=n; i1++)
		{
			for (int j1=1; j1<=i1; j1++)
				cin>>a[i1][j1];
		}
		dp[1][1] = a[1][1];
		for (int i=2; i<=n; i++)
		{
			for (int j=1; j<=i; j++)
			{
				if (j==1)
				{
					dp[i][j] = dp[i-1][j] + a[i][j];
				}
				else if (j==i)
				{
					dp[i][j] = dp[i-1][j-1] + a[i][j];
				}
				else 
				{
					dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + a[i][j];
				}
			}
		}
		int ans = -1;
		for (int i=1; i<=n; i++)
		{
			if (dp[n][i] > ans) ans = dp[n][i];
		}
		cout<<ans<<endl;
	}
} 
