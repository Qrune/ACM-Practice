#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t,p,n;
	int a[101][101];
	int val[101][101];
	int dp[101][101];
	memset(a,0,sizeof(a));
	memset(val,0,sizeof(val));
	cin>>t;
	for (int i=1; i<=t; i++)
	{
		cin>>a[i][0]>>n;
		a[i][0] *= 100;
		for (int j=1; j<=n; j++)
		{
			cin>>val[i][j]>>a[i][j];
			a[i][j] *= 100;
		}
		for (int k=1; k<=n; k++)
		{
			for (int v = a[i][0]; v>=a[i][k]; v--)
			{
				dp[i][v] = dp[i][v-a[i][k]] + val[i][k];
			}
		}
	}
	for (int i=1; i<=t; i++)
	{
		cout<<dp[i][a[i][0]]<<endl;
	}
}
