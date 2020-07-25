/*
There's a scientist named Brook who is interested in budding of cells. He has one container which initially has only a single cell. Now Brook wants n number of 
cells in his container. So he can change the number of cells in container in 3 different ways - 
1. Double the number of cells in the container
2. Increase the number of cells in the container by 1
3. Decrease the number of cells in the container by 1

Now, all the operations above have different costs have associated with them x,y,z respectivley for the above operations. 
Help Brook in finding the minimum cost to generate n cells in the container starting from one cell.

*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(int n, int x,int y,int z){
    
    ll dp[n+1];
    dp[0] = 0;
    dp[1] = 0;
    
    for (int i=2;i<=n;i++){
        if (i & 1){
            dp[i] = min(dp[i-1]+y, dp[(i+1)/2]+x+z);   // tricky part -> simplified
        }else{
            dp[i] = min(dp[i/2]+x, dp[i-1]+y);
        }
    }
    return dp[n];
}

int main(){
    int n = 5;
    int x = 2;
    int y = 1;
    int z = 3;
    
    ll ans = solve(n,x,y,z);
    cout << ans << "\n";
}
