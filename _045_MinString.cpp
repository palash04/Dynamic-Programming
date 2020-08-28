/*
https://www.geeksforgeeks.org/smallest-length-string-with-repeated-replacement-of-two-distinct-adjacent/

*/

#include <bits/stdc++.h>
using namespace std;

string s;

int dp[101][101][101];


// O(n^3)
int go(int a,int b,int c) {
    int &ans = dp[a][b][c];
    if (ans != -1) {
        return ans;
    }
    
    if (a == 0 and b == 0 ) {
        return ans = c;
    }
    if (a == 0 and c == 0 ) {
        return ans = b;
    }
    if (b == 0 and c == 0 ) {
        return ans = a;
    }
    
    if (a == 0) {
        return ans = go(a+1, b-1, c-1);
    }
    
    if (b == 0) {
        return ans = go(a-1, b+1, c-1);
    }
    
    if (c == 0) {
        return ans = go(a-1, b-1, c+1);
    }
    
    return ans = min(go(a-1,b-1,c+1),min(go(a-1,b+1,c-1),go(a+1,b-1,c-1)));
}

void solve() {
    cin>>s;
    int freq[3] = {0};
    for (char c : s) {
        freq[c-'a']++;
    }
    memset (dp, -1 ,sizeof dp);
    int ans = go(freq[0], freq[1], freq[2]);
    cout << ans << "\n";
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}
