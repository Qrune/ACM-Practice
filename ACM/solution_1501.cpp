#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a[100][2];
int b[1000];
int x = 0;
void dfs(int i, int k)
{
	b[k] ++;
	if (k>x) x=k;
	if (a[i][1]) dfs(a[i][1],k+1);
	if (a[i][2]) dfs(a[i][2],k+1);
}
int main()
{
	int n;
	int ans = 0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i][1]>>a[i][2];
	}	
	dfs(1,1);
	for (int i=1; i<1000; i++)
	{
		if (b[i]>ans) ans = b[i];
	}
	cout<<ans<<' '<<x<<endl;
}
