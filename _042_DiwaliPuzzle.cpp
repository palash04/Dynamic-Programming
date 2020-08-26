/*

Its Diwali time and everyone is busy decorating there homes using light bulbs. 
The light bulbs are arranged in a row. 
Little bob is bored of participating in contests so he decided to write 1 for every bulb which is on and 0 for every bulb which is off and 
creates an array of size equal to number of light bulbs. Since he is a bright kid he looks at his array and calculates the sum of all the 
adjacent pairwise products and wonders how many such combinations exist. More formally you are given an array of size n (consisting of 0 and 1 only) 
and k = a1a2 + a2a3 + a3a4 + … an-1an. You have to find out how many combinations of these light bulbs of size n (on and off) will give the sum of products equal to given value k. 
You have to calculate this value modulo 10^6+3.

*/


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000003


int n,k;

int dp[105][3][105];

int go(int pos, int prev, int cnt) {
    if (pos == n) {
        if (cnt == k) {
            return 1;
        }
        return 0;
    }
    
    if (dp[pos][prev][cnt] != -1) {
        return dp[pos][prev][cnt];
    }
    
    int ans = 0;
    
    if (prev == 1) {
        ans += go(pos+1, 1, cnt+1);
    }else {
        ans += go(pos+1, 1, cnt);
    }
    
    ans = ans % mod;
    
    ans += go(pos+1, 0, cnt);
    
    ans = ans % mod;
    return dp[pos][prev][cnt] = ans;
}

void solve() {
    cin>>n>>k;
    memset (dp, -1, sizeof dp);
    int ans = go(1,0,0) + go(1,1,0);
    cout << ans%mod << "\n";
}

signed main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}
