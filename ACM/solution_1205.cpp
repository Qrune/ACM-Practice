#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

string a[100];
int main()
{
	int i=1;
	while(cin>>a[i]&&getchar()==' ')
	{
		i++;
	}
	for (int j=i; j>0; j--)
	{
		cout<<a[j]<<" ";
	}
	return 0;
}
