/*
https://www.codechef.com/AUG14/problems/TSHIRTS
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[1025][101];
vector<vector<int>> v;
int ALL_PERSON;

int calc(int mask, int tid){
    if(mask == ALL_PERSON){
        return 1;
    }
    if (tid == 101){
        return 0;
    }
    
    if (dp[mask][tid] != -1){
        return dp[mask][tid];
    }
    
    int ans = 0;
    
    ans = calc(mask, tid+1);
    
    for (int p:v[tid]){
        if ((mask&(1<<p)) == 0){
            int sub = calc((mask|(1<<p)), tid+1);
            ans = (ans%mod + sub%mod)%mod;
        }
    }
    return dp[mask][tid] = ans;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(dp, -1, sizeof dp);
        int n;
        cin>>n;
        ALL_PERSON = (1<<n)-1;
        v = vector<vector<int>>(110,vector<int>());
        cin.get();
        for (int i=0;i<n;i++){
            string s;
            getline(cin,s);
            stringstream ss(s);
            string tmp;
            while (ss>>tmp){
                v[stoi(tmp)].push_back(i);
            }
        }
        
        for (int i=0;i<=100;i++){
            sort(v[i].begin(),v[i].end());
        }
        int ans = calc(0,1);
        cout << ans << "\n";
    }
    
}
