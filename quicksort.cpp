#include<iostream>
#include<string.h>
using namespace std;
int a[100];
void quicksort(int i, int j)
{
	int l = i;
	int r = j;
	int mid = a[(i+j)/2];
	while (i<=j)
	{
		while (a[i]<mid) i++;
		while (a[j]>mid) j--;
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
	int mark[1005];
	memset(mark,1,sizeof(mark));
	int n;
	cin>>n;
	int k = 0;
	int tmp;
	for (int i=1; i<=n; i++)
	{
		cin>>tmp;
		if (mark[tmp])
		{
			k++;
			a[k] = tmp;
			mark[tmp] = 0;
		}
	}
	quicksort(1,k);
	cout<<k<<endl;
	for (int i=1; i<=k; i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
