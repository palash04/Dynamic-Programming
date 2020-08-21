/*
https://atcoder.jp/contests/dp/tasks/dp_d
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

void solve(){
    int N,W;
    cin>>N>>W;
    vi w(N+1),p(N+1);
    for (int i=1;i<=N;i++){
        cin>>w[i];
        cin>>p[i];
    }
    
    int dp[N+1][W+1];
    for (int i=0;i<=W;i++) dp[0][i] = 0;
    for (int i=0;i<=N;i++) dp[i][0] = 0;
    
    for (int i=1;i<=N;i++){
        for (int j=1;j<=W;j++){
            if (w[i] > j) {
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max( dp[i-1][j] , dp[i-1][j-w[i]]+p[i]);
            }
        }
    }
    cout << dp[N][W] << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}
