#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string m;
	for (int i=0; i<n; i++)
	{
		cin>>m;
		if (m=="0")
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<m.length()<<endl;
		}
	}
}
