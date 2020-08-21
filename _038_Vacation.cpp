/*
https://atcoder.jp/contests/dp/tasks/dp_c
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

int n;
vi a,b,c;

int dp[100005][4];
       
int go(int pos, int last){
    if (pos == n){
        return 0;
    }
    if (dp[pos][last] != -1){
        return dp[pos][last];
    }
    int ans = INT_MIN;
    if (last != 1){
        ans = max(ans, go(pos+1,1) + a[pos]);
    }
    if (last != 2){
        ans = max(ans, go(pos+1,2) + b[pos]);
    }
    if (last != 3){
        ans = max(ans, go(pos+1,3) + c[pos]);
    }
    return dp[pos][last] = ans;
}

void solve(){
    cin>>n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for (int i=0;i<n;i++){
        for (int j=0;j<=2;j++){
            if (j == 0){
                cin>>a[i];
            }else if (j == 1){
                cin>>b[i];
            }else{
                cin>>c[i];
            }
        }
    }
    memset(dp, -1, sizeof dp);
    int ans = go(0,0);
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}
