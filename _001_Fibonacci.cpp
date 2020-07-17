#include <bits/stdc++.h>
using namespace std;

// recursive approach
int fibRecursive(int n){
	if (n == 0 or n == 1){
		return n;
	}

	return fibRecursive(n-1) + fibRecursive(n-2);
}

// top down (recursive + memoization) approach
int fibRecursiveMem(int n,int dp[]){
	if (n == 0 or n == 1){
		return n;
	}
	if (dp[n] != 0){
		return dp[n];
	}
	int ans = fibRecursiveMem(n-1,dp) + fibRecursiveMem(n-2,dp);
	return dp[n] = ans;
}

// bottom up dp approach
int fibDP(int n){
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	for (int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

// dp space optimized approach
int fibDPSpaceOp(int n){
	int a = 0;
	int b = 1;
	int c = a+b;
	for (int i=2;i<=n;i++){
		c= a + b;
		a = b;
		b = c;
	}
	return c;
}

int main(){
	int n;
	cin>>n;
	int dp[100] = {0};
	cout << fibDPSpaceOp(n) << "\n";
}
