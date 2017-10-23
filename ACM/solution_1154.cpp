#include<iostream>
#include<cstring>
using namespace std;
int w[203] = {0};
int dp[203][203];
int max(int a, int b)
{
	if (a>b) return a;
	return b;
}
int main()
{
	int n,ans,wi;
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>wi;
		w[i] = wi;
		w[i+n] = wi;
	}
	memset(dp,0,sizeof(dp));
	for (int j=2; j<n+n; j++)
		for (int i=j-1; i>=1&&j-i<n; i--)
			for (int k=i; k<j; k++)
			{
				dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]+w[i]*w[k+1]*w[j+1]);
				if (dp[i][j] > ans) ans = dp[i][j];
			}
	cout<<ans;
	return 0;
}
