#include<iostream>
using namespace std;
int main()
{
	string a;
	int n;
	cin>>a>>n;
	int ans = 0;
	int t;
	for (int i=0; i<a.length();i++)
	{
		if ((a[i] >='A')&&(a[i]<='F'))
		{
			t = a[i] - 'A';
			ans = ans * n + t+ 10;
		}
		if ((a[i] >= '0')&&(a[i]<= '9'))
		{
			t = a[i] - '0';
			ans = ans * n + t;
		}
	}
	cout<<ans;
}
