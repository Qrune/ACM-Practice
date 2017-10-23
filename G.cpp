#define PI 3.141592654
#define E 2.71828182846
#include <cmath>
#include<iostream>
using namespace std;
int l(int n)
{
    int s=1;
    if(n>3)
        s=log10(2*PI*n)/2+n*log10(n/E)+1;
    return s;
}
int main()
{
	string n;
	cin>>n;
	long long a = n.length();
	if (n=="1")
		cout<<1;
	else if (n=="2")
		cout<<2;
	else if (n=="6")
		cout<<3;
	else if (n=="24")
		cout<<4;
	else if (n=="120")
		cout<<5;
	else if (n=="720")
		cout<<6;
	else if (n=="5040")
		cout<<7;
	else
	{
		for (long i=8; i<1000000; i++)
		{
			if (l(i) == a)
			{
				cout<<i;
				break;
			}
		}
	}
}
