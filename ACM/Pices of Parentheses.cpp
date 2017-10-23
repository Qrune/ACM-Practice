#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 310;
int dp[maxn][maxn];
char str[maxn];
using namespace std;
int result = 0;
bool match(char a, char b){
	return (a=='(' && b==')'); 
}
int dfs(int l, int r){
	if (l>r)
		return dp[l][r] = 0;
	if (l==r)
		return dp[l][r] = 0;
	if (!match(str[l],str[r]))
		return dp[l][r] = 0;
		
	if (dp[l][r] != -1){
		result = max(result,dp[l][r]);
		return dp[l][r];
	}
	int ans = -1;
	if (match(str[l],str[r])){
		cout<<"outside match"<<endl;
		ans = max(ans,dfs(l+1,r-1) + 2);
		for (int i=l+1; i<r; i++){
			cout<<"i"<<i<<endl;
			if (match(str[l],str[i]) && match(str[i+1],str[r])){
				cout<<"match"<<l<<i<<i+1<<r<<endl;
				ans = max(ans,dfs(l,i) + dfs(i+1,r));
			}
		}
	}
	result = max(result,ans);
	return dp[l][r] = ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	cin>>str;
	for (int i=0; i<n; i++)
		cout<<str[i];
	for (int gap = 1; gap<n; gap++){
		for (int i=0; i< n-gap; i++){
			cout<<i<<i+gap<<dfs(i,i+gap)<<endl;
		}
	}
	cout<<"result"<<result<<endl;
}

