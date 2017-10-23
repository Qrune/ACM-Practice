#include<iostream>
using namespace std;
int sol(int n)
{
	if (n==1) return 0;
	int ans=0;
	for (int i=1; i<=n/2; i++)
	{
		ans += sol(i)+1;
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<sol(n)+1<<endl;
}
