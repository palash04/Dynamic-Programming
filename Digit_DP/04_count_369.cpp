/*

A number is said to be a 369 number if

The count of 3s is equal to count of 6s and the count of 6s is equal to count of 9s.
The count of 3s is at least 1.
For Example 12369, 383676989, 396 all are 369 numbers whereas 213, 342143, 111 are not.

Given A and B find how many 369 numbers are there in the interval [A, B]. Print the answer modulo 1000000007.

Input Format
The first line contains the number of test cases (T) followed by T lines each containing 2 integers A and B.

Constraints
T<=100

1<=A<=B<=10^50

Output Format
For each test case output the number of 369 numbers between A and B inclusive

Sample Input
3

121 4325

432 4356

4234 4325667

Sample Output

60

58

207159


 */

#include <bits/stdc++.h>
using namespace std;

/* macros */
#define inf 1e9
#define int long long int
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

string s;
string a,b;

int dp[52][2][18][18][18];

bool checkForA() {
    int freq[3] = {0};
    for (auto c : a) {
        if (c == '3') {
            freq[0]++;
        }
        if (c == '6') {
            freq[1]++;
        }
        if (c == '9') {
            freq[2]++;
        }
    }
    return freq[0] and (freq[0] == freq[1]) and (freq[1] == freq[2]);
}

int go (int pos, int tight, int c3, int c6, int c9) {

    if (c3 >= 18 or c6 >= 18 or c9 >= 18) {
        return 0;
    }

    if (pos == s.size()) {
        if (c3!=0 and (c3 == c6) and (c6 == c9) ) {
            return 1;
        }
        return 0;
    }

    if (dp[pos][tight][c3][c6][c9] != -1) {
        return dp[pos][tight][c3][c6][c9];
    }

    int ans = 0;

    int en = tight ? (s[pos] - '0') : 9;

    for (int i=0;i<=en;i++) {
        ans += go (pos + 1, tight & (i == en), c3+(i==3), c6+(i==6), c9+(i==9));
        ans %= mod;
    }

    return dp[pos][tight][c3][c6][c9] = ans;
}

void solve() {
    cin>>a>>b;

    s = b;
    memset(dp, -1, sizeof dp);
    int ans1 = go (0, 1, 0, 0, 0);

    s = a;
    memset(dp, -1, sizeof dp);
    int ans2 = go (0, 1, 0, 0, 0);

    int ans = ans1 - ans2;
    ans += checkForA();
    ans %= mod;

    cout << ans << "\n";
}

int32_t main(){
    fastio
    tc
    ret
}
