#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	int a[100][100];
	int count=1;
	cin>>n;
	int hang = (n+1)/2;
	int lie = (n+1)/2;
	a[hang][lie] = 1;
	int m = 2;
	int i = 1;
	while (count != n*n)
	{
		a[hang][++lie] = ++count;
		for (i=1; i<m; i++)
		{
			a[--hang][lie] = ++count;
		}
		for (i=1; i<=m; i++)
		{
			a[hang][--lie] = ++count;
		}
		for (i=1; i<=m; i++)
		{
			a[++hang][lie] = ++count;
		}
		for (i=1; i<=m; i++)
		{
			a[hang][++lie] = ++count;
		}
		m+=2;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	long sum=0;
	for (int i=1; i<=n; i++)
	{
		sum = sum + a[i][i];
		sum = sum + a[i][n-i+1];
	}
	cout<<sum-1<<endl;
	return 0;
}
