#include<iostream>
using namespace std;
int gcd(int x, int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}
int main()
{
	int x,y;
	cin>>x>>y;
	int p = x*y;
	int ans = 0;
	for (int i=x; i*i<=p; i+=x)
	{
		if ((p%i==0)&&(gcd(p/i,i)==x)) ans++;
	}
	cout<<ans*2<<endl;
}
