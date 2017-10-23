#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


typedef __int64 LL;
const LL mod = 1000000007;
const LL maxn = 710;
LL dp[maxn][maxn][3][3], match[maxn], tep[maxn];

void get_macth (char a[])
{
    int p = 0;
    for (int i=0; a[i]; i++)
    {
        if (a[i] == '(')
            tep[p ++] = i;
        else
        {
            match[i] = tep[p-1];
            match[tep[p-1]] = i;
            p --;
        }
    }
}

void dfs (int l, int r)
{
    if (l + 1 == r)
    {
        dp[l][r][0][1] = 1;
        dp[l][r][1][0] = 1;
        dp[l][r][0][2] = 1;
        dp[l][r][2][0] = 1;
        return ;
    }
    
    else if (match[l] == r)
    {
        dfs (l+1, r-1);
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
            {
                if (j != 1)
                    dp[l][r][0][1] = (dp[l][r][0][1] + dp[l+1][r-1][i][j]) % mod;
                if (i != 1)
                    dp[l][r][1][0] = (dp[l][r][1][0] + dp[l+1][r-1][i][j]) % mod;
                if (j != 2)
                    dp[l][r][0][2] = (dp[l][r][0][2] + dp[l+1][r-1][i][j]) % mod;
                if (i != 2)
                    dp[l][r][2][0] = (dp[l][r][2][0] + dp[l+1][r-1][i][j]) % mod;
            }
        return ;
    }
    
    else
    {
        int nu = match[l];
        dfs (l, nu);
        dfs (nu+1, r);

        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                for (int x=0; x<3; x++)
                    for (int y=0; y<3; y++)
                        if (!(x==1&&y==1 || x==2&&y==2))
                        dp[l][r][i][j] = (dp[l][r][i][j] + dp[l][nu][i][x]*dp[nu+1][r][y][j]) % mod;
    }
    
}

int main ()
{
    char s[maxn];
    
    while (scanf ("%s", s) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        int len = strlen (s);
        get_macth (s);
        dfs (0, len-1);

        LL ans = 0;
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                ans = (ans + dp[0][len-1][i][j]) % mod;
        printf ("%I64d\n", ans);
        
    }
    return 0;
}
