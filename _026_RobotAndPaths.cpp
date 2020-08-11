/*

https://www.codechef.com/status/CD1IT4

*/

#include <bits/stdc++.h>
using namespace std;

/* macros */
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define mi(a,b) map<a,b>
#define tc int t;cin>>t;while (t--){solve();}
#define notc solve();
#define newline cout << "\n";
#define mod 1000000007
#define ret return 0;
#define sz(x) (int)x.size();
#define rep(i,a,b) for(int i=a;i<b;i++)
#define srt(x) sort(x.begin(), x.end())
#define modadd(x,y) ((x%mod)+(y%mod))%mod


void solve(){
    int m,n,p;
    cin>>m>>n>>p;
    vector<vector<char>> board(m+1,vector<char>(n+1,'.'));
    bool isValid = true;
    for (int i=0;i<p;i++){
        int x,y;
        cin>>x>>y;
        board[x][y] = 'X';
        if (x==m && y==n) isValid = false;
    }
    if (!isValid) {
        cout << 0 << "\n";
        return;
    }
    vector<vector<int>> dp(m+1,vi(n+1,0));
    if (board[1][1] != 'X'){
        dp[1][1] = 1;
    }else{
        cout << 0 << "\n";
        return;
    }
    for (int j=2;j<=n;j++){
        if (board[1][j] != 'X'){
            dp[1][j] = dp[1][j-1];
        }
    }
    for (int i=2;i<=m;i++){
        if (board[i][1] != 'X'){
            dp[i][1] = dp[i-1][1];
        }
    }
    for (int i=2;i<=m;i++){
        for (int j=2;j<=n;j++){
            if (board[i][j] != 'X'){
                dp[i][j] = modadd(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[m][n] << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}


