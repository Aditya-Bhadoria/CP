#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    // dp[node][0] -> ways node can be white
    // dp[node][1] -> ways node can be black
    
    // void dfs(int par, int node, vll g[], vector<vll> &dp){
    //     bool check = true;
    //     for(auto it : g[node]){
    //         if(it == par) continue;
    //         dfs(node, it, g, dp);
    //         check = false;
    //         dp[node][0] = (dp[node][0]*(dp[it][0] + dp[it][1])) % mod;
    //         dp[node][1] = (dp[node][1]*dp[it][0]) % mod;
    //     }
    //     if(check){
    //         dp[node][0] = 1;
    //         dp[node][1] = 1;
    //     }
    // }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}