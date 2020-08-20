/*
https://atcoder.jp/contests/dp/tasks/dp_a
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
#define inf 1e9;

int n;
vi nums;

int dp[100005];
int go(int pos){
    
    if (pos == n){
        return 0;
    }
    if (pos > n){
        return inf;
    }
    
    if (dp[pos] != -1){
        return dp[pos];
    }
    
    int ans = INT_MAX;
    int op1 = go(pos+1) + abs(nums[pos] - nums[pos+1]);
    int op2 = go(pos+2) + abs(nums[pos] - nums[pos+2]);
    
    ans = min(ans, min(op1,op2));
    
    return dp[pos] = ans;
}

void solve(){
    cin>>n;
    nums.clear();
    nums.resize(n+1);
    rep(i,1,n+1) cin>>nums[i];
    memset(dp, -1, sizeof dp);
    int ans = go(1);
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}
