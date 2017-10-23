#include<iostream>
using namespace std;
int a[10001][3];
void sort(long l,long r)
{
	long i = l;
	long j = r;
	long mid = (i+j) / 2;
	while(i<=j)
	{
		while (a[i][2]<a[mid][2]) i++;
		while (a[j][2]>a[mid][2]) j--;
		if (i<=j)
		{
			long temp,temp1,temp2=0;
			temp = a[i][1];
			a[i][1] = a[j][1];
			a[j][1] = temp;
			temp1 = a[i][2];
			a[i][2] = a[j][2];
			a[j][2] = temp1;
			temp2 = a[i][3];
			a[i][3] = a[j][3];
			a[j][3] = temp2;		
			i++;
			j--;	
		}
	}
	if (i<r) sort(i,r);
	if (l<j) sort(l,j);
}
int main()
{
	long n;
	cin>>n;
	for (long i=0; i<n; i++)
	{
		cin >>a[i][1]>>a[i][2]>>a[i][3];
	}
	sort(0,n-1);
	cout<<endl;
	for (long i=0; i<n; i++)
	{
		cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;
	}
	int max = -100;	
	for (int i=1; i<n; i++)
	{
		long k = 0;
		for (int j=0; j<i; j++)
		{
			if (a[i][1]>=a[j][2])
			{
				if (a[j][3] > k)
				k = a[j][3];
			}
		}
		a[i][3] = a[i][3] + k;
		if (max < a[i][3])
		{
			max = a[i][3];
		}
	}
	cout<<max;
}
