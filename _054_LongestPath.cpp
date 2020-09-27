/*
https://atcoder.jp/contests/dp/tasks/dp_g
*/

#include <bits/stdc++.h>
using namespace std;

/* macros */
#define inf 1e9
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vt vector
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define tc int t;cin>>t;while (t--){solve();}
#define gtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": " << solve() << "\n";TC++;}
#define gvtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": "; vsolve(); TC++;}
#define notc solve();
#define newline cout << "\n";
#define mod 1000000007
#define ret return 0;
#define sz(x) (int)x.size();
#define rep(i,a,b) for(int i=a;i<b;i++)
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())

const int N = 1e5+1;
int n,m;
vector<int> adj[N];
vector<int> indegree;

int dp[N];

int go (int u) {
    
    if (dp[u] != -1) {
        return dp[u];
    }
    
    int ans = 0;
    for (auto v : adj[u]) {
        ans = max(ans, go (v) + 1);
    }
    return dp[u] = ans;
}

void solve() {
    cin>>n>>m;
    indegree.resize(n+1,0);
    rep (i,0,m) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    
    vi start;
    for (int i=1;i<=n;i++) {
        if (indegree[i] == 0) start.push_back(i);
    }
    memset(dp, -1, sizeof dp);
    int ans = INT_MIN;
    for (int i=0;i<start.size();i++) {
        ans = max(ans, go (start[i]));
    }
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc  
    ret
}
