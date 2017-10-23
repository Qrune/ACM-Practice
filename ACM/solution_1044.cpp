#include<iostream>
#include<string.h>
#include <stdio.h>
using namespace std;
int main()
{
	int n;
	int temp;
	int stock[21];
	int top = 0;
	int a[100];
	stock[top] = 30001;
	int left,right,mid;
	int count = 1;
	while(scanf("%d",&n)!=EOF)
    {
    	a[count]=n;
    	count++;
    }
	for (int i=1; i<=n; i++)
	{
		if (a[i]<=stock[top])
		{
			stock[++top] = a[i];
		}
		else 
		{
			left = 1; right = top;
			while (left<=right)
			{
				mid = (left+right)/2;
				if (a[i]>=stock[mid])
				{
					right = mid-1;
				}
				else
				{
					left = mid+1;
				}
			}
			stock[left] = a[i];
		}
	}
	cout<<top<<endl;
	top = 0;
	memset(stock,0,sizeof(stock));
	stock[0] = -1;
	for (int i=1; i<=n; i++)
	{
		if (a[i]>=stock[top])
		{
			stock[++top] = a[i];
		}
		else 
		{
			left = 1; right = top;
			while (left<=right)
			{
				mid = (left+right)/2;
				if (a[i]<=stock[mid])
				{
					right = mid-1;
				}
				else
				{
					left = mid+1;
				}
			}
			stock[left] = a[i];
		}
	}
	cout<<top;
}
