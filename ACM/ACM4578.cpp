#include<iostream>
#include<cstring>
int max(int a, int b)
{
	if (a>b)
		return a;
	return b;
}
int min(int a, int b)
{
	if (a<b)
		return a;
	return b;
}
using namespace std;
int main()
{
	int n;
	int s;
	int t;
	int v[203];
	int dp[20][203];
	scanf("%d",&n);
	while(n!=0)
	{
		memset(v,0,sizeof(v));
		memset(dp,-9999999,sizeof(dp));
		cin>>s>>t;
		for (int i=0; i<n; i++)
		{
			scanf("%d",&v[i]);
		}
		for (int i=0; i<=s; i++)
		{
			dp[1][i] = v[i];
		}
		for (int i=2; i<=t; i++)
		{
			for (int j=max(0,i-1); j<=min(i*s-1,n); j++)
			{
				for (int k=max(0,j-s);k<j; k++)
				{
					dp[i][j] = max(dp[i][j],dp[i-1][k]+v[j]);
				}
			}
		}
		int def = dp[0][n];
		scanf("%d",&n);
	}
	return 0;
}
