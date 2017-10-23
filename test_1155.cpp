#include<iostream>  
#include<stdio.h>  
#include<memory.h>  
#include<algorithm>  
#define MAXM 65  
#define MAXN 32055  
using namespace std;  
int n,m;  
int v[MAXM],p[MAXM],q[MAXM],w[MAXM];  
int s[MAXM][MAXM];    //s[i][j]????i??j???????  
int s_ind[MAXM];      //s_ind[i]????i?????  
int f[MAXN/10];  
int F[MAXN/10];  
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		n/=10;
		memset(s_ind,0,sizeof(s_ind));
		memset(F,0,sizeof(F));
		for (int i=1; i<=m; i++)
		{
			scanf("%d%d%d",&v[i],&p[i],&q[i]);
			v[i]/=10;
			w[i] = v[i] * p[i];
			if (q[i])
				s[q[i]][s_ind[q[i]]++]=i;
		}
	for (int i=1; i<=m; i++)
	{
		if (q[i])
			continue;
				memset(f,0,sizeof(f));
		for (int j=0; j<s_ind[i]; j++)
		{
			int cur_son=s[i][j];
			for (int k=n-v[i]; k>=v[cur_son]; k--)
			{
				f[k]=max(f[k],f[k-v[cur_son]]+w[cur_son]);				
			}
		} 
		for (int j=n; j>=v[i]; j--)
			for (int k=j; k>=v[i]; k--)
			{
				F[j] = max(F[j],F[j-k]+f[k-v[i]]);
			}
	}
	printf("%d\n",F[n]*10);
	}
}

