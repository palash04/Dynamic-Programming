/*
 
https://www.spoj.com/problems/DAGCNT2/

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);

const int N = 20010;

int n,m;
vector<vector<int>> adj(N);
int wt[N];
int in[N];
bitset<N> reach[N];
vector<int> vec;

void toposort() {
    queue<int> q;
    for (int i=1;i<=n;i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int val = q.front();q.pop();
        vec.push_back(val);
        for (auto it : adj[val]) {
            in[it]--;
            if (in[it] == 0) {
                q.push(it);
            }
        }
    }

}

void solve() {
    cin>>n>>m;
    for(int i=1 ; i<=n; ++i)
        cin>>wt[i];

    for(int i=1 ; i<=m; ++i) {
        int from, to;
        cin>>from>>to;
        adj[from].push_back(to);
        ++in[to];
    }
    toposort();

    for(int i = n-1; i >= 0; --i) {
        reach[vec[i]] = reach[vec[i]].set(vec[i]);
        for(auto x: adj[vec[i]]) {
            reach[vec[i]] |= reach[x];
        }
    }

    for(int i = 1; i<=n; ++i) {
        int ans = 0;
        for(int j = 1; j<=n; ++j) {
            if(reach[i][j]) {
                ans += wt[j];
            }
        }
        cout << ans << " ";
    }

    cout << "\n";

    vec.clear();
    for (int i=1;i<=n;i++) {
        adj[i].clear();
        reach[i].reset();
    }

}

int32_t main() {
    fastio
    int t;
    cin >> t;
    while ( t-- ) {
        solve();
    }
}
