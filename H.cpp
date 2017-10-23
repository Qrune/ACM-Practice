#include<iostream>
#include<cstring>
using namespace std;
int max(int a, int b)
{
	if (a>b)
		return a;
	return b;
}
int min(int a, int b)
{
	if (a<b)
		return a;
	return b;
}
int main()
{
	int flag = 0;
	int a1[101];
	int b1[101];
	int dp1[100001];
	int dp2[100001];
	int h,b;
	int maxh = 0;
	int maxb = 0;
	cin>>h;
	for (int i=1; i<=h; i++)
	{
		cin>>a1[i];
		maxh += a1[i];
	}
	cin>>b;
	for (int i=1; i<=b; i++)
	{
		cin>>b1[i];
		maxb +=b1[i];
	}
	for (int i=1; i<=maxh; i++)
	{
		dp1[i] = 2000;
	}
	for (int i=1; i<=maxb; i++)
	{
		dp2[i] = 2000;
	}
	dp1[0] = 0;
	dp2[0] = 0;
	
	for (int i=1; i<=h; i++)
	{
		for (int v=maxh; v>=a1[i]; v--)
		{
			dp1[v] = min(dp1[v],dp1[v - a1[i]] + 1);
		}	
	}
	
	for (int i=1; i<=b; i++)
	{
		for (int v=maxb; v>=b1[i]; v--)
		{
			dp2[v] = min(dp2[v], dp2[v - b1[i]] + 1);
		}
	}
	int top = min(maxh,maxb);
	int ans = 1000;
	for (int i=1; i<=top; i++)
	{
		if ((dp1[i] + dp2[i] <=2000) && (dp1[i] + dp2[i] !=0))
		{
			if (ans>dp1[i]+dp2[i]) ans = dp1[i] + dp2[i];
		}
	}
	if (ans!=1000) cout<<ans;
	else cout<<"impossible";
}
