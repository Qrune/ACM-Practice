#include<iostream>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	int n,m,k,s;
	int c[105];
	int w[105];
	int f[105][105];
	while (scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF)
	{
		for (int i=0; i<k; i++)
		{
			scanf("%d%d",&w[i],&c[i]);
		}
		memset(f,0,sizeof(f));
		for (int i=0; i<k; i++)
			for (int j=c[i]; j<=m; j++)
				for (int l=1; l<=s; l++)
					f[j][l] = max(f[j][l],f[j-c[i]][l-1]+w[i]);
		int flag = 0;
		int locate = 0;
		for (int i=0; i<=m; i++)
		{
			if (flag)
				break;
			for (int j=0; j<=s; j++)
			{
				if (f[i][j] >= n)
				{
					locate = i;
					flag = 1;
					break;
				}
			}
		}
		if(flag)  
            cout<<m-locate<<endl;  
        else  
            cout<<"-1"<<endl;
	}
}
