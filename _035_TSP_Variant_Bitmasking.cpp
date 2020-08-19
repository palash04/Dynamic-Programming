/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/fifth-1/description/
*/

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define inf 1e9

int n,m,u,v,d,e,E;

vector<pair<int,pi>> adj[20];

void addEdge(int u,int v,int d,int e){
    adj[u].push_back({v,{d,e}});
    adj[v].push_back({u,{d,e}});
}


// TC: O(2^n * n * E)
int dp[1<<15][20][105];
int go(int mask, int x, int energy){
    if (mask == ((1<<n)-1)){
        return energy >= 0 ? 0 : inf;
    }
    if (energy <= 0){
        return inf;
    }
    if (dp[mask][x][energy] != -1){
        return dp[mask][x][energy];
    }
    
    int ans = inf;
    for (auto a:adj[x]){
        int y = a.first;
        int dist = a.second.first;
        int en = a.second.second;
        
        if (!(mask & (1<<y))) {
            ans = min(ans, dist + go((mask | (1<<y)) , y, energy-en));
        }
    }
    return dp[mask][x][energy] = ans;
}

void solve(){
    
    cin>>n>>m>>E;
    for (int i=0;i<m;i++){
        cin>>u>>v>>d>>e;
        --u;
        --v;
        addEdge(u, v, d, e);
    }
    memset(dp, -1, sizeof dp);
    int ans = go(1,0,E);
    if (ans >= inf) cout << "-1\n";
    else cout << ans << "\n";
}

int main(){
    solve();
}
