/*

Given n wines in a row, with integers denoting the cost of each wine respectively. 
Each year you can sale the first or the last wine in the row. However, the price of wines increases over time. 
Let the initial profits from the wines be P1, P2, P3…Pn. 
On the Yth year, the profit from the ith wine will be Y*Pi. 
For each year, your task is to print “beg” or “end” denoting whether first or last wine should be sold.
Calculate the maximum profit from all the wines.

*/

#include <bits/stdc++.h>
using namespace std;

// O(n^2)
int profit(vector<int> &wines,int i,int j,int y,int dp[][100]){
    // Base case
    if (i > j){
        return 0;
    }
    
    // lookup
    if (dp[i][j] != 0){
        return dp[i][j];
    }
    
    // Recursive case
    int op1 = wines[i]*y + profit(wines, i+1, j, y+1, dp);
    int op2 = wines[j]*y + profit(wines, i, j-1, y+1, dp);
    
    return dp[i][j] = max(op1,op2);
}

int main(){
    vector<int> wines = {2,3,5,1,4};
    int n = (int)wines.size();
    int dp[100][100] = {0};
    int ans = profit(wines, 0, n-1, 1, dp);
    cout << ans << "\n";
    return ans;
}
