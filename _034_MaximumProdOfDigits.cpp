/*
  
 Find the maximum product of digits of a number between two numbers.
 Ex. Between 51 and 62 => Max ans = 45 (59: 5 x 9 = 45)
 Ex. Between 1 and 100 => Max ans = 81 (81: 9 x 9 = 81)
 
*/

#include <bits/stdc++.h>
using namespace std;

/* macros */
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vt vector
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define tc int t;cin>>t;while (t--){solve();}
#define notc solve();
#define newline cout << "\n";
#define mod 1000000007
#define ret return 0;
#define sz(x) (int)x.size();
#define rep(i,a,b) for(int i=a;i<b;i++)
#define srt(x) sort(x.begin(), x.end())

string a;
string b;
int dp[20][2][2][2];

int go(int pos,bool t1,bool t2,int st){
    if (pos == a.size()){
        return 1;
    }
    if (dp[pos][t1][t2][st] != -1){
        return dp[pos][t1][t2][st];
    }
    int ans = 0;
    
    int lb = t1 ? (a[pos]-'0') : 0;
    int up = t2 ? (b[pos]-'0') : 9;
    
    for (int i=lb;i<=up;i++){
        int val;
        if (st == 0 and i == 0){
            val = 1;
        }else{
            val = i;
        }
        
        ans = max(ans, val*go(pos+1, t1&(i==lb), t2&(i==up), (st|(i>0)) ));
    }
    return dp[pos][t1][t2][st] = ans;
}

void solve(){
    memset(dp, -1, sizeof dp);
    //cin>>a>>b;
    reverse(a.begin(),a.end());
    while (a.size() < b.size()){
        a.push_back('0');
    }
    reverse(a.begin(),a.end());
    int ans = go(0,1,1,0);
    cout << ans << "\n";
}

int32_t main(){
    a = "1";
    b = "100";
    solve();
}
