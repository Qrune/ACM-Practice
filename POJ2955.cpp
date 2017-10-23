#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 105;
char str[maxn];
int dp[maxn][maxn];

bool match(char a, char b){
	return (a=='('&&b==')') || (a=='['&&b==']');
}

int dfs(int l, int r){
	if (l>r)
		return 0;
	if (l==r)
		return dp[l][r] = 0;
	if (l+1 == r)
		return dp[l][r] = match(str[l],str[r]);
	if (dp[l][r] != -1)
		return dp[l][r];
	int ans = dfs(l+1,r);
	for (int i=l+1; i<=r; i++)
		if (match(str[l],str[i]))
			ans = max(ans,dfs(l+1,i-1)+dfs(i+1,r)+1);
	return dp[l][r] = ans;
}
int main(){
    while (~scanf("%s", str) && str[0]!='e'){
        memset(dp, -1, sizeof(dp));
        int len = strlen(str);
        dfs(0, len-1);
        printf("%d\n", 2*dp[0][len-1]);
    }
    return 0;
}
