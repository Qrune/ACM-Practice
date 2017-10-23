#include<iostream>
#include<cstring>
using namespace std;
long long n,m,x1,x2,y1,y2;
long long dp[60][60];
int main()
{
	cin>>n>>m;
	cin>>x1>>y1>>x2>>y2;
	memset(dp,0,sizeof(dp));
	dp[x1][y1] = 1;
	for (int i=x1; i<=x2; i++)
		for (int j=1; j<=m; j++)
		{
			if (i-1>=x1&&j-2>=1)
			dp[i][j] += dp[i-1][j-2];
			if (i-1>=x1&&j+2<=m)
			dp[i][j] += dp[i-1][j+2];
			if (i-2>=x1&&j-1>=1)
			dp[i][j] +=dp[i-2][j-1];
			if (i-2>=x1&&j+1>=1)
			dp[i][j] +=dp[i-2][j+1];
		}
	cout<<dp[x2][y2];
}
