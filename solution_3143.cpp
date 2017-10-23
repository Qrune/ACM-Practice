#include<iostream>
#include<string.h>

using namespace std;
int count = 1;
int a[1000][2];
int b[1000];
int c[1000];
int d[1000];
void qian(int i)
{
	b[count] = i;
	count++;
	if (a[i][1]!=0) qian(a[i][1]);
	if (a[i][2]!=0) qian(a[i][2]);
}
void zhong(int i)
{
	if (a[i][1]!=0) zhong(a[i][1]);
	b[count] = i;
	count++;
	if (a[i][2]!=0) zhong(a[i][2]);
}
void hou(int i)
{
	if (a[i][1]!=0) hou(a[i][1]);
	if (a[i][2]!=0) hou(a[i][2]);
	b[count] = i;
	count++;
}
int main()
{
	int n;
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	memset(b,0,sizeof(b));
	qian(1);
	for (int i=1; i<=n; i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	count = 1;
	memset(b,0,sizeof(b));	
	zhong(1);
	for (int i=1; i<=n; i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	count = 1;
	memset(b,0,sizeof(b));
	hou(1);
	for (int i=1; i<=n; i++)
	{
		cout<<b[i]<<" ";
	}
	
}
