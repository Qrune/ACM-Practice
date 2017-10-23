#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
char str[maxn];
int dp[maxn][maxn];
bool match(char a, char b){
	return (a=='('&&b==')')||(a=='['&&b==']');
}

int dfs(int l, int r){
	if (l>r) 
		return dp[l][r] = 0;
	if (l==r)
		return dp[l][r] = 1;
	if (dp[l][r] != inf)
		return dp[l][r];
	int ans = dp[l][r];
	if (match(str[l],str[r]))
		ans = min(ans,dfs(l+1,r-1));
	for (int i=l; i<r; i++)
		ans = min(ans, dfs(l,i)+dfs(i+1,r));
	return dp[l][r] = ans;
}

void print(int l, int r){
	if (l>r)
		return;
	if (l==r){
		if (str[l]=='('||str[r]==')')
			printf("()");
		else
			printf("[]");
		return;
	}
	int ans = dp[l][r];
	if (match(str[l],str[r])&& ans == dp[l+1][r-1])
	{
		putchar(str[l]);
		print(l+1,r-1);
		putchar(str[r]);
		return;
	}
	for (int i=l; i<r; i++)
	{
		if (ans == dp[l][i] + dp[i+1][r]){
			print(l,i);
			print(i+1,r);
			return;
		}
	}
}
int main(){
	while (fgets(str,maxn,stdin)){
		int n = strlen(str);
		str[n-1] = '\0';
		--n;
		memset(dp,inf,sizeof(dp));
		dfs(0,n-1);
		print(0,n-1);
		putchar('\n');
	}
}
