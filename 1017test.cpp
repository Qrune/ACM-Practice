#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,k;
	int i;
	string a;
	int map[50][50];
	int dp[50][50];
	cin>>n>>k;
	cin>>a;
	for (int i=0; i<=n; i++)
	{
		int tmp =0;
		for (int j=i; j<=n; j++)
		{
			tmp = tmp*10 + a[j]-'0';
			map[i][j] = tmp;
		}
	}
	memset(dp,0,sizeof(dp));
	for (int i=0; i<n; i++)
	{
		dp[i][0] = map[0][i];
	}
	for (int i=0; i<=n; i++)
	{
		for (int nk=1; nk<=k; nk++)
		for (int j=0; j<=n; j++)
		{
			dp[i][nk] = max(dp[j][nk-1]*map[j+1][i],dp[i][nk]);
		}
	}
	cout<<dp[n-1][k]<<endl;
}
 
