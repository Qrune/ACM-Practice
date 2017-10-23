#include<iostream>
#include<cstdio>
using namespace std;
int f[55][55][55][55];
int a[55][55];
int max(int a,int b, int c, int d)
{
	if (a<b) a=b;
	if (c<d) c=d;
	if (a<c) return c;
	return a;
}
int main()
{
	int m,n;
	cin>>m>>n;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
			cin>>a[i][j];
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
			for (int k=1; k<=m; k++)
				for (int l=1; l<=n; l++)
				{
					if (i!=k||j!=l)
					f[i][j][k][l] = a[i][j] + a[k][l] + max(f[i-1][j][k-1][l],f[i][j-1][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k][l-1]);					
				}
	if (f[m-1][n][m][n-1]>f[m][n-1][m-1][n]) cout<<f[m-1][n][m][n-1];
	else cout<<f[m][n-1][m-1][n];
}
