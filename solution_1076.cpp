#include<iostream>
using namespace std;
int a[100000];
void quicksort(int l, int r)
{
	int i = l;
	int j = r;
	int mid = a[(i+j)/2];
	while (i<=j)
	{
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i<=j)
		{
			a[0] = a[i];
			a[i] = a[j];
			a[j] = a[0];
			i++;
			j--;
		}
	}
	if (i<r) quicksort(i,r);
	if (l<j) quicksort(l,j);
}
int main()
{
	int n;
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	quicksort(1,n);
	for (int i=1; i<=n; i++)
	{
		cout<<a[i]<<" ";
	}
}
