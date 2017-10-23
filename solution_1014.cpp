#include<iostream>
using namespace std;
int w[31];
int b[31][20000] = {0};

int main()
{
	int v,n;
	cin>>v;
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>w[i];
	}
	for (int j=1; j<v+1; j++)
	{
		for (int i=1; i<n+1; i++)
		{
			if (w[i]>j)
			{
				b[i][j] = b[i-1][j];
			}
			else
			{
				if (b[i-1][j-w[i]] + w[i] > b[i-1][j])
				{
					b[i][j] = b[i-1][j-w[i]] + w[i];
				}
				else 
				{
					b[i][j] = b[i-1][j];
				}
			}
		}
	}
	for (int j=1;j<v+1; j++)
	{
		for (int i=1; i<n+1; i++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	cout<<v-b[n][v];
	return 0;
}
