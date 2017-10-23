#include<iostream>
#include<cstring>
using namespace std;
int f[100001][4];
int a[100001];
int main()
{
	int n,m;
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>m;
		for (int j=0; j<m; j++)
		{
			cin>>a[j];
		}
		memset(f,-100000,sizeof(f));
		f[0][0] = a[0];
		f[0][2] = 1;
		f[0][1] = 1;
		
		for (int j=1; j<m; j++)
		{
			if (a[j] <= f[j-1][0] + a[j])
			{
				f[j][0] = f[j-1][0] + a[j];
				f[j][2] = j+1;
				f[j][1] = f[j-1][1];
			}
			else
			{
				f[j][0] = a[j];
				f[j][1] = j+1;
				f[j][2] = j+1;
			}
		}
		int ans=0;
		int start,end;
		for (int j=0; j<m; j++)
		{
			if (f[j][0] > ans)
			{
				ans = f[j][0];
				start = f[j][1];
				end = f[j][2];
			}
		}
		cout<<ans<<" "<<start<<" "<<end<<endl;
	}
} 
