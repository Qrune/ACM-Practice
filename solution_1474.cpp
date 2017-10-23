#include<iostream>
using namespace std;
int main()
{
	char a[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int m,n;
	cin>>m>>n;
	int count = 0;
	int b[100];
	while(m>=n)
	{
		count++;
		b[count] = m%n;
		m = m/n;
	}
	b[++count] = m;
	for (int i=count; i>0; i--)
	{
		cout<<a[b[i]];
	}
}
