#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
	if (a>b) return a;
	return b;
}
using namespace std;
int main()
{
	int n,m,t,i,j;
	double total,q,A,B,C;
	double money[50];
	double dp[50];
	int len = 0;
	char ch;
	while(scanf("%lf %d",&total,&t))
	{
		len = 0;
		memset(money,0,sizeof(money));
		if (t==0) break;
		for (i=1; i<=t; i++)
		{
			cin>>n;
			A=0;
			B=0;
			C=0;
			int flag = 1;
			for (j=0; j<n; j++)
			{
				scanf(" %c:%lf",&ch,&q);
				if(ch!='A' && ch!='B' && ch!='C' || q>600)
				{
					flag = 0;
					break;
				}
				if (ch=='A') A+=q;
				else if (ch=='B') B+=q;
				else if (ch=='C') C+=q;
			}
		   if(flag && A+B+C<=1000 && A<=600 && B<=600 &&C<=600)    
		          money[len++]=A+B+C;
		}
		memset(dp,-10000,sizeof(dp));
		dp[0] = 0;
		for (i=0; i<len; i++)
		{
			for (j=len; j>=1; j--)
			{
				if (dp[j-1]+money[i] <= total)
					dp[j]=max(dp[j],dp[j-1]+money[i]);
			}
		}
		int sum=0;
		for(i=1;i<=len;i++)
		{
			if(dp[sum]<dp[i])
				sum=i;
		}
		printf("%.2lf\n",dp[sum]);
	}
	return 0;
}
