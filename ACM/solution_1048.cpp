#include<iostream>
#include<cstring>
using namespace std;
int w[106] = {0};
int dp[106][106];
int min(int a,int b)
{
	if (a<b) return a;
	return b;
}
int main()
{
	memset(dp,0x3f3f3f3f,sizeof(dp));
	int n,t;
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>t;
		w[i] = w[i-1] + t;
		dp[i][i] = 0;
	}
	for (int j=2; j<=n; j++)
	{
		for (int i=j-1; i>=1; i--)
		{
			for (int k=i; k<j; k++)
			{
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+w[j]-w[i-1]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
