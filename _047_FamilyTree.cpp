/*
https://www.codechef.com/problems/FAMTREE
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

const int N = 1e5+5;
int n;
vi W(N), P(N);
vi mi(N), ma(N);
vi adj[N];
int ans = 0;

void dfs(int i, int par ) {
    for (auto it : adj[i]) {
        if (it != par) {
            dfs(it, i);
            
            ma[i] = max(ma[i], ma[it]);
            mi[i] = min(mi[i], mi[it]);
        }
    }
    
    ma[i] = max(ma[i], W[i]);
    mi[i] = min(mi[i], W[i]);
    
    ans = max(ans, abs(W[i] - ma[i]));
    ans = max(ans, abs(W[i] - mi[i]));
}

void solve() {
    cin>>n;
    W.clear();
    P.clear();
    mi.clear();
    ma.clear();
    mi.resize(N);
    ma.resize(N);
    W.resize(N);
    P.resize(N);
    rep (i,1,n+1) adj[i].clear();
    rep (i,1,n+1) ma[i] = INT_MIN;
    rep (i,1,n+1) mi[i] = INT_MAX;
    for (int i=1;i<=n;i++) {
        cin>>W[i];
    }
    int root = 0;
    for (int i=1;i<=n;i++) {
        cin>>P[i];
        if (P[i] == -1) root = i;
        else {
            adj[P[i]].push_back(i);
        }
    }
    
    dfs(root, 0);
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}
