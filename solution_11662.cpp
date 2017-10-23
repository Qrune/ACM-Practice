#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1001
#define M 81
int a[M],n,m;
int f[M][M][N], ans[N];
void add(int *s, int *t)
{
	int len = max(s[0],t[0]);
	for (int i=1; i<=len; i++)
	{
		s[i] += t[i];
		s[i+1] +=s[i]/10;
		s[i] %=10;
	}
	if (s[len+1]) len ++;
	s[0] = len;
}
int cmp(int *s, int *t)
{
	if (s[0]>t[0]) return 1;
	if (s[0]<t[0]) return -1;
	for (int i=s[0]; i>=1; --i)
	{
		if (s[i]>t[i]) return 1;
		if (s[i]<t[i]) return -1;
	}
	return 1;
}
void cpy(int *s, int *t)
{
	memset(s,0,sizeof(0));
	for (int i=0; i<=t[0]; i++)
	{
		s[i] = t[i];
	}
}
int main()
{
	cin>>n>>m;
	int t1[N],t2[N];
	for (int i=1; i<=n; i++)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		for (int j=1; j<=m; ++j)
		{
			cin>>a[j];
			int len =1;
			for (len =1; a[j]; len++)
			{
				f[j][1][len] = a[j] % 10;
				a[j] /=10;
			}
			f[j][1][0] = len;
			cpy(t1,f[j][1]);
			add(f[j][1],t1);
			memset(t1,0,sizeof(t1));	
		}
		for (int l=2; l<=m; ++l)
		{
			for (int j=1; j+l-1<=m; ++j)
			{
				memset(t1,0,sizeof(t1));
				memset(t2,0,sizeof(t2));
				add(t1,f[j+1][l-1]); add(t1,f[j+1][l-1]); add(t1,f[j][1]);
				add(t2,f[j][l-1]); add(t2,f[j][l-1]); add(t2,f[j+l-1][1]);
				if (cmp(t1,t2)>0)
					cpy(f[j][l],t1);
				else cpy(f[j][l],t2);
			}
		}
		add(ans,f[1][m]);
	}
    for(int i=ans[0];i>0;--i)
    printf("%d",ans[i]);
    printf("\n");
 	return 0;
}
