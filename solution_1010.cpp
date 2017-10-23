#include<iostream>
#include<cstring>
using namespace std;
int n,m,x,y;
int a[21][21];
int main()
{
	cin>>n>>m>>x>>y;
	memset(a,0,sizeof(a));
	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++)
			a[i][j] = 1;
	a[x][y] = 0;
	a[x+1][y+2] = 0;
	a[x+2][y+1] = 0;
	if (x>=1) a[x-1][y+2] = 0;
	if (x>=2) a[x-2][y+1] = 0;
	if ((x>=2)&&(y>=1))a[x-2][y-1] = 0;
	if ((x>=1)&&(y>=2))a[x-1][y-2] = 0;
	if (y>=2) a[x+1][y-2] = 0;
	if (y>=1) a[x+2][y-1] = 0;
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=m; j++)
		{
			if (a[i][j] == 0) continue;
			if (i==0 && j==0) continue;
			else if (i==0) a[i][j] = a[i][j-1]; 
			else if (j==0) a[i][j] = a[i-1][j];
			else a[i][j] = a[i-1][j] + a[i][j-1];
		}
	}
	cout<<a[n][m];
	
}
