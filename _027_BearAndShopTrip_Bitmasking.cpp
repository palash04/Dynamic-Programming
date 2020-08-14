/*
https://www.codechef.com/problems/SHOPTRIP
*/

#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<pair<int,int>> coordinates;
vector<int> ingredients;

long double distance(pair<int,int> p1, pair<int,int> p2){
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    
    return sqrt(dx*dx + dy*dy);
}

long double dist[50][50] = {0};
long double dp[1<<13][50];

long double shopTrip(int mask, int idx){
    
    if ((mask == ((1<<k)-1)) && (idx==0)){
        return 0;
    }
    
    if (dp[mask][idx] != -1){
        return dp[mask][idx];
    }
    
    dp[mask][idx] = INT_MAX;
    for (int i=0;i<=n;i++){
        if ((mask|ingredients[i]) != mask || (i==0)){
            dp[mask][idx] = min(dp[mask][idx], dist[idx][i] + shopTrip((mask|ingredients[i]), i));
        }
    }
    return dp[mask][idx];
}


int main(){
    string temp;
    int t;
    cin>>t;
    while (t--){
        coordinates.clear();
        ingredients.clear();
        cin>>n>>k;
        coordinates.push_back({0,0});
        ingredients.push_back(0);
        for (int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            coordinates.push_back({x,y});
        }
        int possible = 0;
        for (int i=0;i<n;i++){
            cin>>temp;
            reverse(temp.begin(),temp.end());
            int temp_mask = 0;
            for (int i=0;i<temp.size();i++){
                temp_mask |= ((1<<i)*(temp[i]-'0'));
            }
            possible |= temp_mask;
            ingredients.push_back(temp_mask);
        }
        int ALL = (1<<k)-1;
        if (possible != ALL){
            cout << "-1\n";
            continue;
        }
        
        memset(dist, 0, sizeof dist);
        for (int i=0;i<=n;i++){
            for (int j=0;j<=n;j++){
                dist[i][j] = distance(coordinates[i], coordinates[j]);
            }
        }
        for (int i=0;i<(1<<k);i++){
            for (int j=0;j<=n;j++){
                dp[i][j] = -1;
            }
        }
        long double ans = shopTrip(0,0);
        cout << fixed << setprecision(9) << ans << "\n";
    }
}
