#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int a[100000], b[100000], c[100000];
char al[100][10000], bl[100][10000];
int f(int la, int lb)
{
	if (la>lb) return 1;
	if (la<lb) return 0;
	for (int i=la-1; i>=0; i--)
	{
		if (a[i]>b[i]){
			return 1;
			break;
		}
		if (a[i]<b[i]){
			return 0;
			break;
		}
	}
	return 1;
}
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
	lenc = 1;
	for (i=0; i<lena; i++) a[lena-i-1] = al[1][i] - 48;
	for (i=0; i<lenb; i++) b[lenb-i-1] = bl[1][i] - 48;
	int t = f(lena,lenb);
	if (lena>lenb) lenc = lena; else lenc = lenb;
	if (t==1)
	{
	
		for (int i=0; i<lenc; i++)
		{
			if (a[i]<b[i])
			{
				a[i+1] -=1; 
				a[i] +=10;
			}
			c[i] = a[i] - b[i];
		}
	}
	if (t==0)
	{
		cout<<"-";
		for (int i=0; i<lenc; i++)
		{
			if (b[i]<a[i])
			{
				b[i+1] -=1; 
				b[i] +=10;
			}
			c[i] = b[i] - a[i];
		}
	}
	while (c[lenc]==0&&lenc>=1)
	lenc--;
	for (i=lenc; i>=0; i--)
	cout<<c[i];
	cout<<endl;
	system("pause");
	return 0;

}
