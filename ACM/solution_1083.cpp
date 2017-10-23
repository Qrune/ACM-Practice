#include<iostream>
using namespace std;
int main()
{
	long i=0;
	long n;
	cin>>n;
	while (i<n)
	{
		n-=i;
		i++;
	}
	if (i%2 == 0)
	{
		cout<<n<<"/"<<i+1-n;
	}
	else 
	{
		cout<<i+1-n<<"/"<<n;
	}
	return 0;
}
