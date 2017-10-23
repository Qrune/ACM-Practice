#include<iostream>
using namespace std;
int a[10001] = {0};
int main()
{
	int n;
	cin>>n;
	int total = 0;
	int dist = 0;
	int count = 0;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
		total = total + a[i];
	}
	int av = total/n;
	for (int i=1; i<=n; i++)
	{
		if (dist!=0) count++;
		a[i] += dist;
		dist = a[i]-av;	
		cout<<dist<<endl;
	}
	cout<<count;
}
