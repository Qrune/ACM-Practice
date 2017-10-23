#include<iostream>
using namespace std;
long gcd(long x, long y)
{
	if (y==0) return x;
	else return gcd(y,x%y);
}
int main()
{
	long x,y;
	cin>>x>>y;
	cout<<gcd(x,y)<<endl;
}
