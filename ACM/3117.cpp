#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int a[100000], b[100000], c[100000];
char al[100][10000],bl[100][10000];
int main()
{
	int lena, lenb, lenc;
	int i;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	scanf("%s %s", &al[1],&bl[1]);
	lena = strlen(al[1]);
	lenb = strlen(bl[1]);
	for (i=0; i<lena; i++) a[lena-i] = al[1][i] - 48;
	for (i=0; i<lenb; i++) b[lenb-i] = bl[1][i] - 48;
	for (i=1; i<=lena; i++)
	{
		lenc=i-1;
		for (int j=1; j<=lenb; j++)
		{
			lenc = lenc + 1;
			c[lenc] += a[i] * b[j];
		}
	}
	for (i=1; i<=lenc; i++)
	{
		if (c[lenc] >= 10)
		lenc++;
		c[i+1] += c[i]/10;
		c[i] = c[i] % 10; 	
	}

	for (i=lenc; i>0; i--)
	{
		cout<<c[i];
	}
	cout<<endl;
}

