/*

https://codeforces.com/problemset/problem/429/B

*/

#include <bits/stdc++.h>
using namespace std;

/* macros */
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vt vector
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define tc int t;cin>>t;while (t--){solve();}
#define notc solve();
#define newline cout << "\n";
#define mod 1000000007
#define ret return 0;
#define sz(x) (int)x.size();
#define rep(i,a,b) for(int i=a;i<b;i++)
#define srt(x) sort(x.begin(), x.end())

const int N = 1e3+5;
const int M = 1e3+5;

int gym[N][M];
int dp1[N][M];
int dp2[N][M];
int dp3[N][M];
int dp4[N][M];

void solve(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>gym[i][j];
        }
    }
    
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp1[i][j] = -1;
            dp2[i][j] = -1;
            dp3[i][j] = -1;
            dp4[i][j] = -1;
        }
    }
    dp1[1][1] = gym[1][1];
    dp2[n][1] = gym[n][1];
    dp3[1][m] = gym[1][m];
    dp4[n][m] = gym[n][m];
    for (int i=2;i<=m;i++){
        dp1[1][i] = dp1[1][i-1] + gym[1][i];
        dp2[n][i] = dp2[n][i-1] + gym[n][i];
    }
    for (int i=2;i<=n;i++){
        dp1[i][1] = dp1[i-1][1] + gym[i][1];
        dp3[i][m] = dp3[i-1][m] + gym[i][m];
    }
    for (int i=n-1;i>=1;i--){
        dp2[i][1] = dp2[i+1][1] + gym[i][1];
        dp4[i][m] = dp4[i+1][m] + gym[i][m];
    }
    for (int i=m-1;i>=1;i--){
        dp3[1][i] = dp3[1][i+1] + gym[1][i];
        dp4[n][i] = dp4[n][i+1] + gym[n][i];
    }
    for (int i=2;i<=n;i++){
        for (int j=2;j<=m;j++){
            dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + gym[i][j];
        }
    }
    for (int i=n-1;i>=1;i--){
        for (int j=2;j<=m;j++){
            dp2[i][j] = max(dp2[i+1][j], dp2[i][j-1]) + gym[i][j];
        }
    }
    for (int i=2;i<=n;i++){
        for (int j=m-1;j>=1;j--){
            dp3[i][j] = max(dp3[i-1][j], dp3[i][j+1]) + gym[i][j];
        }
    }
    for (int i=n-1;i>=1;i--){
        for (int j=m-1;j>=1;j--){
            dp4[i][j] = max(dp4[i+1][j], dp4[i][j+1]) + gym[i][j];
        }
    }
    int ans = INT_MIN;
    for (int i=2;i<=n-1;i++){
        for (int j=2;j<=m-1;j++){
            int op1 = dp1[i][j-1] + dp2[i+1][j] + dp3[i-1][j] + dp4[i][j+1];
            int op2 = dp1[i-1][j] + dp2[i][j-1] + dp3[i][j+1] + dp4[i+1][j];
            ans = max(ans, max(op1,op2));
        }
    }
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}
