/*

BILLIARDS is a really interesting game. It is played on a green baize with 3 balls-red, white and yellow.
Sheldon and Leonard are playing a game of billiards. Sheldon is playing the game for the first time and is not familiar with the rules. 
So he asks Leonard to explain the rules to him. Leonard explains the rules to Sheldon in the following way:

“A Cannon shot gives 2 points and an In-Off Shot gives 3 points.”

Sheldon is curious, and wants to figure out that given a score X, in how many ways can he get that score by hitting a combination of Cannon and In-Off shots?

Leonard is baffled when he is asked this question.

Your task is to help Leonard in writing a program to compute the total number of ways one can score a total of X points by 
hitting any combination of Cannon and In-Off shots. 
The order in which the shots are hit have importance.

For example, 5 can be scored in two ways, by hitting an In-Off Shot followed by a Cannon shot or a Cannon Shot followed by an In-Off shot. 
A score of 7 can be achieved in three ways – Cannon,In-Off,Cannon Cannon,Cannon,In-Off and In-Off,Cannon,Cannon.

https://www.codechef.com/LRNDSA07/problems/CDQU5/

*/

#include <bits/stdc++.h>
using namespace std;

/* Defines */
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define mi(a,b) map<a,b>
#define tc int t;cin>>t;while (t--){solve();}
#define newline cout << "\n";
#define mod 1000000009
#define ret return 0;

unordered_map<string, int> state;
int helper(int n){
    string key = to_string(n);
    if (n == 0){
        return 1;
    }
    if (n < 0){
        return 0;
    }
    
    if (state.find(key) != state.end()){
        return state[key];
    }
    int a = helper(n-2);
    int b = helper(n-3);
    int res = ((a%mod) + (b%mod))%mod;
    return state[key] = res;
}

vector<int> dp(10000001, 0);

int dphelper(int n){
    dp[0] = 1;
    for (int i=2;i<=n;i++){
        int op1 = 0, op2 = 0;
        if (i-2 >= 0){
            op1 = dp[i-2];
        }
        if (i-3 >= 0){
            op2 = dp[i-3];
        }
        dp[i] = (op1%mod + op2%mod)%mod;
    }
    return dp[n];
}

void solve(){
    int n;
    cin>>n;
    int ans = helper(n);
    cout << ans;
    newline
}

int32_t main(){
    fastio
    tc
    ret
}
