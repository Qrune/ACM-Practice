#include<iostream>
using namespace std;
int f[41][41][41][41] = {0};
int a[351];
int sum[6] = {0};

int max(int a, int b)
{
	if (a>b) return a;
	return b;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	int x;
	for (int i=1; i<=m; i++)
	{
		cin>>x;
		sum[x] ++;
	}
	for (int i=0; i<=sum[1]; i++)
	  for (int j=0; j<=sum[2]; j++)
	    for (int k=0; k<=sum[3]; k++)
	      for (int p=0; p<=sum[4]; p++)
	      {
	    	if (i!=0) f[i][j][k][p] = max(f[i][j][k][p],f[i-1][j][k][p]);
	    	if (j!=0) f[i][j][k][p] = max(f[i][j][k][p],f[i][j-1][k][p]);
	    	if (k!=0) f[i][j][k][p] = max(f[i][j][k][p],f[i][j][k-1][p]);
	    	if (p!=0) f[i][j][k][p] = max(f[i][j][k][p],f[i][j][k][p-1]);
	    	f[i][j][k][p] = f[i][j][k][p] + a[i+j*2+k*3+p*4];
	      }
	cout<<f[sum[1]][sum[2]][sum[3]][sum[4]];
}
