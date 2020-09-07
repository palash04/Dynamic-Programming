/*
https://www.spoj.com/problems/PT07Z/
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

const int N = 1e4+5;
int n;
vt<vi> adj(N);
vi max_depth(N);
int ans = 0;

void dfs(int u, int par) {
    
    int max1=0, max2=0;
    
    for (auto v : adj[u]) {
        if (v!=par) {
            dfs(v,u);
            
            if (max_depth[v] + 1 >= max1) {
                int tmp = max1;
                max1 = max_depth[v] + 1;
                max2 = tmp;
            }else if (max_depth[v] + 1 > max2) {
                max2 = max_depth[v] + 1;
            }
            
        }
    }
    max_depth[u] = max1;
    ans = max(ans, max1 + max2);
}

void solve() {
    cin>>n;
    adj.clear();
    max_depth.clear();
    adj.resize(N);
    max_depth.resize(N);
    
    for (int i=1;i<=n-1;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}
