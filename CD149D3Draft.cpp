dfs(int l, int r)
{
	if (l+1 == r)
	{
		dp[l][r][0][1] = 1;
		dp[l][r][1][0] = 1;
		dp[l][r][0][2] = 1;
		dp[l][r][2][0] = 1;
		return;
	}
	if (match[l] == r)
	{
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
			{
				if (j!=1) dp[l][r][0][1] += dp[l+1][r-1][i][j];
				if (j!=2) dp[l][r][0][2] += dp[l+1][r-1][i][j];
				if (i!=1) dp[l][r][1][0] += dp[l+1][r-1][i][j];
				if (i!=2) dp[l][r][2][0] += dp[l+1][r-1][i][j];
			}
		return;
	}
	dfs(l,match[l]);
	dfs(match[l]+1,r);
	
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			for (int k=0; k<3; k++)
				for (int p=0; p<3; p++)
				{
					if (j && j==k) continue;
					dp[l][r][i][p] += (dp[l][match[l]][i][j]*dp[match[l]+1][r][k][p])% mod;
				}
}
