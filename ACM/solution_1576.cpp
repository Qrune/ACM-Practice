#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int stock[1000];
	stock[0] = -1;
	int top = 0;
	int temp;
	for (int i=1; i<=n; i++)
	{
		cin>>temp;
		if (temp>=stock[top])
		{
			stock[++top] = temp;
		}
		else
		{
			int low = 1;
			int high = top;
			int mid;
			while(low<=high)
			{
				mid = (low+high)/2;
				if (temp<stock[mid]) 
				{
					high = mid - 1;
				}
				else
				{
					low = mid + 1;
				}
			}
			stock[low] = temp;
		}
	}
	cout<<top;
}
