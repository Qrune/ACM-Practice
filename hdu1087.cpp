#include<iostream>
using namespace std;
int main()
{
	int n,num;
	while(1)
	{
		cin>>n;
		int last = -1;
		int sum = 0;
		int ans = -1;
		if (n==0) break; 
		for (int i=0; i<n; i++)
		{
			cin>>num;
			if (num + sum > num && num>last)
			{
				sum = num + sum;
			}
			else
			{
				sum = num;
			}
			if (sum>ans)
			{
				ans = sum;
			}
			last = num;
		} 
		cout<<ans<<endl;
	}
}
