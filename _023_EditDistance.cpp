/*
https://leetcode.com/problems/edit-distance/

Recursion in action : https://user-images.githubusercontent.com/26361028/89529888-25e18d00-d80b-11ea-933d-f2625bfb5f08.jpeg

*/


#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX

class Solution {
public:
    // Recursive + Memoization
    unordered_map<string, int> dp;
    int solve(string X,string Y,int m,int n){
        string key = to_string(m) + "_" + to_string(n);
        if (m == 0 || n == 0){
            return max(m,n);
        }

        if (dp.find(key) != dp.end()){
            return dp[key];
        }
        
        int cost = 1;
        if (X[m-1] == Y[n-1]){
            cost = 0;
        }
        
        int op1=inf,op2=inf,op3=inf;
        op1 = solve(X,Y,m,n-1) + 1;
        op2 = solve(X,Y,m-1,n) + 1;
        op3 = solve(X,Y,m-1,n-1) + cost;
        
        return dp[key] = min(min(op1,op2),op3);
        
    }
    
    int solvedp(string X,string Y,int m,int n){
        int dp[m+1][n+1];
        for (int i=0;i<=m;i++){
            dp[i][0] = i;
        }
        for (int j=1;j<=n;j++){
            dp[0][j] = j;
        }
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
                if (dp[i-1][j-1] < dp[i][j]){
                    if (X[i-1] == Y[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                }
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        return solvedp(word1,word2,(int)word1.size(),(int)word2.size());
    }
};
