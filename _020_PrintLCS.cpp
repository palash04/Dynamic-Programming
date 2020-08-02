/*

https://www.geeksforgeeks.org/printing-longest-common-subsequence/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int dp[1005][1005];
    int solve(string X,string Y,int m,int n){
        if (m == 0 || n == 0){
            return 0;
        }
        if (dp[m][n] != -1){
            return dp[m][n];
        }
        
        if (X[m-1] == Y[n-1]){
            return solve(X,Y,m-1,n-1) + 1;
        }
        
        return dp[m][n] = max(solve(X,Y,m-1,n), solve(X,Y,m,n-1));
    }
    
    string printLCS(string X,string Y,int m,int n){
        memset(dp,0,sizeof dp);
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                if (X[i-1] == Y[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int index = dp[m][n];
        string res = string(index,'a');
        
        int i=m,j=n;
        while (i>0 && j>0){
            if (X[i-1] == Y[j-1]){
                res[index-1] = X[i-1];
                i--;
                j--;
                index--;
            }else if (dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
        
        return res;
    }
    
    string longestCommonSubsequence(string text1, string text2) {
        int m = (int)text1.size();
        int n = (int)text2.size();
        memset(dp,-1,sizeof(dp));
        //int ans1 = solve(text1,text2,m,n);
        string res = printLCS(text1,text2,m,n);
        return res;
    }
};

int main(){
    Solution s;
    string X = "abcdefghijkl";
    string Y = "adjklfjkl";
    cout << s.longestCommonSubsequence(X, Y) << "\n";
}
