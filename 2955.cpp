#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;
int v[105];
double dp[10005];
double w[105];
int main()
{
    int t,n;
    double p;
    cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int sum = 0;
        cin>>p>>n;
        p = 1.0-p;
        for (int i=0; i<n; i++)
        {
            cin>>v[i]>>w[i];
            w[i] = 1.0 - w[i];
            sum += v[i];
        }
        
        dp[0] = 1.0;
        for (int i=0; i<n; i++)
            for (int j = sum; j>=v[i]; j--)
                dp[j] = max(dp[j],dp[j-v[i]]*w[i]);
        
        for (int i=sum; i>=0; i--)
        {
            if (dp[i] > p)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;    
}