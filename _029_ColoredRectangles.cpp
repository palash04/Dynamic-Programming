/*
https://codeforces.com/contest/1398/problem/D
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

int R[201],G[201],B[201];
int dp[201][201][201];

int go(int i, int j, int k){
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    int ans = INT_MIN;
    int op1=0,op2=0,op3=0;
    if (i&&j){
        op1 = R[i-1]*G[j-1] + go(i-1,j-1,k);
    }
    if (j&&k){
        op2 = G[j-1]*B[k-1] + go(i,j-1,k-1);
    }
    if (i&&k){
        op3 = R[i-1]*B[k-1] + go(i-1,j,k-1);
    }
    ans = max(ans, max(op1,max(op2,op3)));
    return dp[i][j][k] = ans;
    
}

void solve(){
    memset(dp,-1,sizeof dp);
    int r,g,b;
    cin>>r>>g>>b;
    
    for (int i=0;i<r;i++) cin>>R[i];
    for (int i=0;i<g;i++) cin>>G[i];
    for (int i=0;i<b;i++) cin>>B[i];
    
    sort(R,R+r);
    sort(G,G+g);
    sort(B,B+b);
    
    int ans = go(r,g,b);
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}
