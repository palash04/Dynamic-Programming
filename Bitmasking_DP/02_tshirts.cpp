/*

https://www.codechef.com/problems/TSHIRTS

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
#define pi pair<int,int>
#define tc int t;cin>>t;while (t--){solve();}
#define gtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": " << solve() << "\n";TC++;}
#define gvtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": "; vsolve(); TC++;}
#define notc solve();
#define mod 1000000007
#define ret return 0;

int n;
vector<vector<int>> t;

int dp[1030][110];

int go (int mask, int tid) {
    if (mask == (1 << n) - 1) {
        return 1;
    }else if (tid > 100) {
        return 0;
    }

    if (dp[mask][tid] != -1) {
        return dp[mask][tid];
    }

    int ans = go (mask, tid + 1);

    for (auto p : t[tid]) {
        if ( (mask & (1 << p)) == 0) {
            ans =  (ans%mod +  (go ( mask | (1 << p) , tid + 1 )) % mod) %mod;
        }
    }
    return dp[mask][tid] = ans;
}

void solve() {
    cin>>n;
    t.clear();
    t.resize(110);
    cin.get();
    for (int i=0;i<n;i++) {
        string s;
        getline(cin,s);
        stringstream ss(s);
        string tmp;
        while (ss>>tmp){
            t[stoi(tmp)].push_back(i);
        }
    }

    memset(dp, -1, sizeof dp);
    int ans = go (0, 1);

    cout << ans << "\n";
}

int32_t main(){
    fastio
    tc
    ret
}
