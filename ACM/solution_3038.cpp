#include<iostream>
#include<string.h>
using namespace std;
int count = 0;
int t(int n)
{
	if (n==1) 
	return count;
	count++;
	if (n%2)
	{
			return t(3*n+1);
	}
	else 
	{
			return t(n/2);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[1001];
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for (int i=1; i<=n; i++)
	{
		count = 0;
		cout<<t(a[i])<<endl;
	}
}
