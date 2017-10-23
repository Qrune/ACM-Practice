#include<iostream>
#include<cstring>
using namespace std;
int a[5][5];
int ans[5][5];

int main()
{
	int n,poi;
	for (int i=1; i<=4; i++)
	{
		for (int j=1; j<=4; j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>n;
	if (n==0)
	{
		for (int i=1; i<=4; i++)
		{
			poi = 1;
			for (int j=1; j<=4; j++)
			{
				if (a[i][j]!=0) 
				{
					if (a[i][j] == ans[i][poi])
					{
						ans[i][poi] += ans[i][poi];
						poi++;
					}
					else
					{
						if (ans[i][poi] != 0)
						{
							poi++;
						}
						ans[i][poi] = a[i][j];
						
					}
				}
			}
		}
	}
	if (n==1)
	{
		for (int j=1; j<=4; j++)
		{
			poi = 1;
			for (int i=1; i<=4; i++)
			{
				if (a[i][j] !=0)
				{
					if (a[i][j] == ans[poi][j]) 
					{
						ans[poi][j] *=2;
						poi++;
					}
					else
					{
						if (ans[poi][j] != 0)
						{
							poi++;
						}
						ans[poi][j] = a[i][j];
					}
				}
			}
		}
	}
	if (n==2)
	{
		for (int i=1; i<=4; i++)
		{
			poi = 4;
			for (int j=4; j>=1; j--)
			{
				if (a[i][j]!=0) 
				{
					if (a[i][j] == ans[i][poi])
					{
						ans[i][poi] += ans[i][poi];
						poi--;
					}
					else
					{
						if (ans[i][poi] != 0)
						{
							poi--;
						}
						ans[i][poi] = a[i][j];
						
					}
				}
			}
		}
	}
	if (n==3)
	{
		for (int j=1; j<=4; j++)
		{
			poi = 4;
			for (int i=4; i>=1; i--)
			{
				if (a[i][j] !=0)
				{
					if (a[i][j] == ans[poi][j]) 
					{
						ans[poi][j] *=2;
						poi--;
					}
					else
					{
						if (ans[poi][j] != 0)
						{
							poi--;
						}
						ans[poi][j] = a[i][j];
					}
				}
			}
		}
	}
	for (int i=1; i<=4; i++)
	{
		for (int j=1; j<=4; j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
