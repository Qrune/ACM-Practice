#include<iostream>
#include<cstring>
using namespace std;
int v[1000];
int w[1000];
int dp[1000];
int max(int a, int b)
{
	if (a>b) return a;
	return b;
}
int main()
{
	int n,vol,num,val,j,i;
	cin>>n;
	for (i=0; i<n; i++)
	{
		memset(v,0,sizeof(v));
		memset(w,0,sizeof(w));
		memset(dp,0,sizeof(dp));
		dp[0] = 0;
		cin>>num>>val;
		for (j=0; j<num; j++)
			cin>>w[j];
		for (j=0; j<num; j++)
			cin>>v[j];
		for (j=0; j<num; j++)
			for (vol=val; vol>=v[j]; vol--)
				dp[vol] = max(dp[vol],dp[vol-v[j]]+w[j]);
		cout<<dp[val]<<endl;
	}
}
