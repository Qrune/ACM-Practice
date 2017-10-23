#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int a[10000],b[10000],c[10000];
char al[100][10000],bl[100][10000];
int main()
{
	int lena,lenb,lenc;
	int i;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	scanf("%s %s", &al[1],&bl[1]);
	lena = strlen(al[1]);
	lenb = strlen(bl[1]);
	i = 1;
	for (i=0; i<lena; i++) a[lena-i] = al[1][i] - 48;
	for (i=0; i<lenb; i++) b[lenb-i] = bl[1][i] - 48;
	while(lenc<=lena||lenc<=lenb)
	{
			c[lenc] = c[lenc] + a[lenc] + b[lenc];
			c[lenc+1] = c[lenc+1] + c[lenc] / 10;
			c[lenc] = c[lenc] % 10;
			lenc++;
	}
	while (c[lenc] == 0 && lenc>1)
	lenc--;
	for (i=lenc; i>0; i--)
	cout<<c[i];
	cout<<endl;
}
