/*
https://cses.fi/problemset/task/1132
*/


#include <iostream>
#include <vector>

using namespace std;

const int N = 200002;

vector<int> adj[N];
vector<int> child(N);
vector<int> depth(N);
vector<pair<int,int>> mxp(N);

void dfs(int u, int par) {
    
    int mx1 = 0;
    int mx2 = 0;
    int mxChild = -1;
    for (auto v : adj[u]) {
        if (v != par) {
            dfs(v, u);
            int h = depth[v] + 1;
            if (h > mx1) {
                mx2 = mx1;
                mx1 = h;
                mxChild = v;
            } else if (h > mx2) {
                mx2 = h;
            }
        }
    }
    child[u] = mxChild;
    depth[u] = mx1;
    mxp[u] = {mx1, mx2};
}

void dfs2(int u, int par) {
    
    if (par != 0) {
        
        if (child[par] == u) {
            int parMax2 = mxp[par].second;
            if (parMax2 + 1 > mxp[u].first) {
                mxp[u].second = mxp[u].first;
                mxp[u].first = parMax2 + 1;
                child[u] = par;
            } else if (parMax2 + 1 > mxp[u].second) {
                mxp[u].second = parMax2 + 1;
            }
        } else {
            int parMax1 = mxp[par].first;
            if (parMax1 + 1 > mxp[u].first) {
                mxp[u].second = mxp[u].first;
                mxp[u].first = parMax1 + 1;
                child[u] = par;
            }
        }
        
    }
    
    for (auto v : adj[u]) {
        if (v != par) {
            dfs2(v, u);
        }
    }
}


void solve() {
    int n;
    cin>>n;
    
    for (int i=1;i<=n;i++) {
        adj[i].clear();
        child[i] = -1;
        depth[i] = 0;
    }
    
    int a,b;
    for (int i=1;i<=n-1;i++) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);
    dfs2(1, 0);
    
    for (int i=1;i<=n;i++) {
        cout << mxp[i].first << " ";
    }
    cout << "\n";
    
}

int main() {
    solve();
}

