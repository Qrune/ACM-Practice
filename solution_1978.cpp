#include<iostream>
using namespace std;
int sol(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 1;
	return sol(n-1) + sol(n-2);
}
int main()
{
	int n;
	cin>>n;
	cout<<sol(n)<<endl;
}
