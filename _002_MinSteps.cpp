#include <bits/stdc++.h>
using namespace std;

// Minsteps to 1
// n -> n/3, n/2, n-1

// Top Down (Recursive + Memoization)
map<string,int> dp;
int minStepsTD(int n){
	string key = to_string(n);
	if (n == 1){
		return 0;
	}	

	if (dp.find(key) != dp.end()){
		return dp[key];
	}

	int ans = 1e9;
	if (n%3 == 0){
		ans = min(ans,minStepsTD(n/3)+1);
	}
	if (n%2 == 0){
		ans = min(ans,minStepsTD(n/2)+1);
	}
	ans = min(ans,minStepsTD(n-1)+1);
	return dp[key] = ans;
}

// Bottom Up approach
int minStepsBU(int n){
	vector<int> dp(n+1,1e9);
	dp[1] = 0;

	for (int i=2;i<=n;i++){
		if (i%3 == 0){
			dp[i] = min(dp[i], dp[i/3]+1);
		}
		if (i%2 == 0){
			dp[i] = min(dp[i],dp[i/2]+1);
		}
		dp[i] = min(dp[i],dp[i-1]+1);
	}
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	int ans = minStepsTD(n);
	cout << ans << "\n";
	ans = minStepsBU(n);
	cout << ans << "\n";
}
