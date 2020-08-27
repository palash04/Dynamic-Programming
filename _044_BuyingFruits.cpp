/*
Prateek went to purchase fruits mainly apples, mangoes and oranges. 
There are N different fruit sellers in a line. Each fruit seller sells all three fruit items, but at different prices. 
Prateek, obsessed by his nature to spend optimally, decided not to purchase same fruit from adjacent shops. 
Also, Prateek will purchase exactly one type of fruit item (only 1kg) from one shop. 
Prateek wishes to spend minimum money buying fruits using this strategy. Help Prateek determine the minimum money he will spend. 
If he becomes happy, he may offer you discount on your favorite course in Coding Blocks ;). All the best!

Constraints - 
1 ≤ T ≤ 10 1 ≤ N ≤ 10^5 Cost of each fruit(apples/mangoes/oranges) per kg does not exceed 10^4

Sample I/p - 
1
3
1 50 50
50 50 50
1 50 50

Sample O/p - 
52

Explanation - 
There are two ways, each one gives 52 as minimum cost. 
One way is buy apples from first shop, mangoes from second shop and apples from third shop or he can buy apples from first shop, 
oranges from second shop and apples from third shop.

Both ways , cost comes up to 1 + 50 + 1 = 52

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long


const int N = 1e5+2;
vector<int> seller[N];
int n;

int dp[100005][4];

int go(int pos, int last) {
    if (pos == n) {
        return 0;
    }
    
    if (dp[pos][last] != -1) {
        return dp[pos][last];
    }
    
    int ans = INT_MAX;
    
    if (last == 0) {
        ans = min(ans, go(pos+1, 1) + seller[pos][1]);
        ans = min(ans, go(pos+1, 2) + seller[pos][2]);
    }else if (last == 1) {
        ans = min(ans, go(pos+1, 0) + seller[pos][0]);
        ans = min(ans, go(pos+1, 2) + seller[pos][2]);
    }else if (last == 2) {
        ans = min(ans, go(pos+1, 0) + seller[pos][0]);
        ans = min(ans, go(pos+1, 1) + seller[pos][1]);
    }else {
        ans = min(ans, go(pos+1, 0) + seller[pos][0]);
        ans = min(ans, go(pos+1, 1) + seller[pos][1]);
        ans = min(ans, go(pos+1, 2) + seller[pos][2]);
    }
    
    return dp[pos][last] = ans;
}

void solve() {
    cin>>n;
    
    for (int i=0;i<n;i++) {
        seller[i].clear();
        seller[i].reserve(3);
    }
    
    for (int i=0;i<n;i++) {
        cin>>seller[i][0];
        cin>>seller[i][1];
        cin>>seller[i][2];
    }
    memset(dp, -1, sizeof dp);
    int ans = go(0, 3);
    cout << ans << "\n";
}

int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}
