/*
https://www.spoj.com/problems/TOURIST/
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long

int h,w;

bool isSafe(int i,int j,vector<vector<char>> &board){
    return (i>=1 && i<=h && j>=1 && j<=w && board[i][j] != '#');
}

int dp[105][105][105];
// O(n^3)
int go(int x1,int y1,int x2,int y2,vector<vector<char>> &board){
    
    if (x1 > h || y1 > w || x2 > h || y2 > w || board[x1][y1] == '#' || board[x2][y2] == '#'){
        return INT_MIN;
    }
    
    if (x1 == h && y1 == w){
        return board[x1][y1] == '*';
    }
    
    if (x2 == h && y2 == w){
        return board[x2][y2] == '*';
    }
    
    if (dp[x1][y1][x2] != -1){
        return dp[x1][y1][x2];
    }
    
    int ans = INT_MIN;
    
    ans = max(ans, go(x1+1,y1,x2+1,y2,board));
    ans = max(ans, go(x1,y1+1,x2,y2+1,board));
    ans = max(ans, go(x1+1,y1,x2,y2+1,board));
    ans = max(ans, go(x1,y1+1,x2+1,y2,board));
    
    ans += (board[x1][y1] == '*');
    ans += (board[x2][y2] == '*');
    if (x1 == x2 and y1 == y2 and board[x1][y1] == '*') ans--;
    
    return dp[x1][y1][x2] = ans;
}


void solve(){
    memset(dp, -1, sizeof(dp));
    cin>>w>>h;
    vector<vector<char>> board(h+1,vector<char>(w+1));
    for (int i=1;i<=h;i++){
        for (int j=1;j<=w;j++){
            cin>>board[i][j];
        }
    }
    //int cost = (board[1][1] == '*') ? 1:0;
    int ans = go(1,1,1,1,board);
    cout << ans << "\n";
}

signed main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
}
