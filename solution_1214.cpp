#include<iostream>
#include<string.h>
using namespace std;
int a[101][2];
void qs(int s,int e)
{
	int i = s;
	int j = e;
	int mid = (s+e)/2;
	while(a[i][2]<a[mid][2]) i++;
	while(a[j][2]>a[mid][2]) j--;
	if (i<=j)
	{
		int temp = a[i][2];
		a[i][2] = a[j][2];
		a[j][2] = temp;
		temp = a[i][1];
		a[i][1] = a[j][1];
		a[j][1] = temp;
		i++;
		j--;
	}
	if (i<e) qs(i,e);
	if (s<j) qs(s,j);
}
int sol(int k, int n)
{
	int m = k+1;
	while ((m<=n) && (a[m][1] < a[k][2]))
	{
		m++;
	}
	cout<<"m "<<m<<endl;
	cout<<"n "<<n<<endl;
	if (m<=n)
	{
		return sol(m,n) + 1;
	}
	else return 0;
}
int main()
{
	memset(a,0,sizeof(a));
	a[0][1]=-1000;
	a[0][2]=-1000;
	int n,q,s;
	int max = -1000;
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>q>>s;
		if (q<s)
		{
			a[i][1] = q;
			a[i][2] = s;
			if (a[i][2]>max) max = s;
		}
		else
		{
			a[i][1] = s;
			a[i][2] = q;
			if (a[i][2]>max) max = s;
		}
	}
	qs(1,n);
	cout<<endl;
	for (int i=1; i<=n; i++)
	{
		cout<<a[i][1]<<" "<<a[i][2]<<endl;
	}
	cout<<sol(0,n);
}
