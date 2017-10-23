#include <iostream>  
#include <cstdio>  
#include <iomanip>  
#include <string>  
#include <cstring>  
#include <climits>  
#include <cmath>  
#include <algorithm>  
#include <queue>  
using namespace std;  
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
int dp[maxn][maxn][2];
int sum[maxn];
int X,V,n;
struct person
{
	int x,b;
}order[maxn];

bool cmp(person a, person b)
{
	return a.x<b.x;
}
int main()
{
	while(cin>>n>>V>>X)
	{
		for (int i=1; i<=n; i++)
			cin>>order[i].x>>order[i].b;
		n++;
		order[n].x = X;
		order[n].b = 0;
		sort(order+1,order+1+n,cmp);
		int temp;
		for (int i=1; i<=n; i++)
			if (order[i].x == X)
			{
				temp = i;
				break;
			}
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				dp[i][j][0] = dp[i][j][1] = inf;
		dp[temp][temp][0] = dp[temp][temp][1] = 0;
		sum[0] = 0;
		for (int i=1; i<=n; i++)
			sum[i] = sum[i-1] + order[i].b;
		for (int i=temp; i>=1; i--)
			for (int j=temp; j<=n; j++)
			{
				if (i==j)
					continue;
				dp[i][j][0] = min(dp[i][j][0],dp[i+1][j][0]+(sum[i]+sum[n]-sum[j])*(order[i+1].x-order[i].x));
				dp[i][j][0] = min(dp[i][j][0],dp[i+1][j][1]+(sum[i]+sum[n]-sum[j])*(order[j].x - order[i].x));
				dp[i][j][1] = min(dp[i][j][1],dp[i][j-1][0]+(sum[i-1]+sum[n]-sum[j-1])*(order[j].x - order[i].x));
				dp[i][j][1] = min(dp[i][j][1],dp[i][j-1][1]+(sum[i-1]+sum[n]-sum[j-1])*(order[j].x - order[j-1].x));
				
			}
		cout<<min(dp[1][n][0],dp[1][n][1])*V<<endl;
	}
}
