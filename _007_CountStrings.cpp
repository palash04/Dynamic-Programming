/*
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.

https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
*/

#include <bits/stdc++.h>
using namespace std;

int rec(int i,int n,int last){
    if (i == n){
        return 1;
    }
    
    int op1=0,op2=0;
    if (last == 1){
        op1 = rec(i+1,n,0);
    }else{
        op1 = rec(i+1,n,0);
        op2 = rec(i+1,n,1);
    }
    
    return op1+op2;
}

int dpBU(int n){
    int dp[100] = {0};
    dp[0] = 1;
    dp[1] = 2;
    
    for (int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}


int main(){
    int n;
    n = 8;
    int ans = rec(0,n,0);
    cout << ans << "\n";
    ans = dpBU(n);
    cout << ans << "\n";
}
