/*
https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<string, int> dp;
int tsp(int mask, int pos, int n, vector<vector<int>> &dist){
    string key = to_string(mask) + "_" + to_string(pos);
    if (mask == ((1<<n)-1)){
        return dist[pos][0];
    }
    
    if (dp.find(key) != dp.end()){
        return dp[key];
    }
    
    int ans = INT_MAX;
    for (int city=0;city<n;city++){
        if ((mask&(1<<city)) == 0){
            int newAns = dist[pos][city] + tsp((mask|(1<<city)), city, n, dist);
            ans = min(ans, newAns);
        }
    }
    return dp[key] = ans;
}

void solve(){
    dp.clear();
    int n;
    cin>>n;
    vector<vector<int>> dist(n+5,vector<int>(n+5));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }
    
    int ans = tsp(1,0,n,dist);
    cout << ans << "\n";
}


signed main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
}
