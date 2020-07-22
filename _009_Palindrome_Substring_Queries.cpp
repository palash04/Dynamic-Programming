/*

Given a string and several queries on the substrings of the given input string to check whether the substring is a palindrome or not.

https://www.geeksforgeeks.org/palindrome-substring-queries/

*/

#include <bits/stdc++.h>
using namespace std;

map<string,bool> dp;
bool solveTD(string s, int l,int r){
    string key = to_string(l) + to_string(r);
    if (abs(l-r) <= 1){
        return s[l] == s[r];
    }
    
    if (dp.find(key) != dp.end()){
        return dp[key];
    }
    
    return dp[key] = solveTD(s,l+1,r-1) && (s[l]==s[r]);
}

void processDP(string s,vector<vector<int>> &dp2){
    int n = (int)s.size();
    for (int i=0;i<n;i++){
        dp2[i][i] = 1;
    }
    
    int i = 0;
    int j = 1;
    while (j<n){
        dp2[i][j] = (s[i] == s[j]);
        i++;
        j++;
    }
    
    for (int k=n-2;k>=1;k--){
        int x=0,y=n-k;
        while (y<n){
            dp2[x][y] = dp2[x+1][y-1] and (s[x] == s[y]);
            x++;
            y++;
        }
    }
}

int main(){
    string s = "abaaabaaaba";
    vector<vector<int>> dp2(s.size(),vector<int>(s.size()));
    
    vector<vector<int>> queries = {
        {0,10},
        {5,8},
        {2,5},
        {5,9},
    };
    
    cout << "Top Down\n";
    for (auto q:queries){
        int l = q[0];
        int r = q[1];
        bool ans = solveTD(s,l,r);
        if (ans){
            cout << "Palindrome\n";
        }else{
            cout << "Not Palindrome\n";
        }
    }
    
    cout << "------------*------------------------*------------\n";
    
    cout << "Bottom Up\n";
    processDP(s,dp2);
    for (auto q : queries){
        int l = q[0];
        int r = q[1];
        if (dp2[l][r]){
            cout << "Palindrome\n";
        }else{
            cout << "Not Palindrome\n";
        }
    }
    
}
