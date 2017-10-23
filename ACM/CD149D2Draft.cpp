#include <cstdio>  
#include <iostream>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
typedef long long ll;  
const int mod = 1000000007;  
  
char str[800];  
int match[800];  
ll dp[800][800][3][3];  
int stk[800];  
int top=-1; 

void dfs(int l, int r)
{
	if (l+1 == r)
	{
		dp[l][r][0][1] = 1;
		dp[l][r][0][2] = 1;
		dp[l][r][1][0] = 1;
		dp[l][r][2][0] = 1;
		return;
	}
	if (match[l] == r)
	{
		dfs(l+1,r-1);
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
			{
				if (j!=1) dp[l][r][0][1] = (dp[l][r][0][1] + dp[l+1][r-1][i][j])%mod;
				if (j!=2) dp[l][r][0][2] = (dp[l][r][0][2] + dp[l+1][r-1][i][j])%mod;
				if (i!=1) dp[l][r][1][0] = (dp[l][r][1][0] + dp[l+1][r-1][i][j])%mod;
				if (i!=2) dp[l][r][2][0] = (dp[l][r][2][0] + dp[l+1][r-1][i][j])%mod;
			}
	}
	else{
	dfs(l,match[l]);
	dfs(match[l]+1,r);
	
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			for (int k=0; k<3; k++)
				for (int p=0; p<3; p++)
				{
					if (j && j==k) continue;
					dp[l][r][i][p] = (dp[l][r][i][p] + (dp[l][match[l]][i][j] * dp[match[l]+1][r][k][p])%mod)%mod;
				}
}
}
int main()  
{  
    scanf("%s",str+1);  
  
    int n=strlen(str+1);  
  
    memset(match,0,sizeof match);  
  
    for(int i=1;i<=n;i++)  
    {  
        if(str[i]=='(')  
            stk[++top]=i;  
        else match[stk[top--]]=i;  
    }  
  
    memset(dp,0,sizeof dp);  
  
    dfs(1,n);  
    ll ans=0;  
    for(int i=0;i<3;i++)  
    for(int j=0;j<3;j++)  
    ans=ans+dp[1][n][i][j];  
    printf("%I64d\n",ans%mod);  
    return 0;  
}
