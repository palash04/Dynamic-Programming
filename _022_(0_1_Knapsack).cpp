/*
https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1005][1005];

// O(N*W)
void solve(){
    int N;
    int W;
    cin>>N>>W;
    memset(dp,0,sizeof dp);
    
    vector<int> profits(N+1);
    vector<int> weights(N+1);
    
    for (int i=1;i<=N;i++){
        cin>>profits[i];
    }
    
    for (int i=1;i<=N;i++){
        cin>>weights[i];
    }
    
    for (int i=1;i<=N;i++){
        for (int j=1;j<=W;j++){
            if (j>=weights[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + profits[i]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[N][W] << "\n";
}

int32_t main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
}
