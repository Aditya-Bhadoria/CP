#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

constexpr int MOD = 1e9 + 7;
int dp[1 << 20][20];
vector<int> rev_adj[20];

void solve() {
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        rev_adj[--v].push_back(--u); // store reverse edges
    }
    dp[1][0] = 1; // base case
    // all possible subsets of visited cities
    for(int mask=1; mask<(1<<n); mask++){
        // path must start at city 0
        if(!(mask & 1)) continue; 
        for(int u=0; u<n; u++){
            // If city u is not even in the current mask, skip
            if (!(mask & (1<<u))) continue;
            // If we reached the destination early, it's a dead end
            if(u == n-1 && mask != (1<<n)-1) continue;
            int prev_mask = mask ^ (1<<u);
            for (int v : rev_adj[u]) {
                if(prev_mask & (1<<v)){
                    dp[mask][u] = (dp[mask][u] + dp[prev_mask][v]) % MOD;
                }
            }
        }
    }
    // ans = ways to visit ALL cities and end at city n-1
    cout << dp[(1<<n)-1][n-1];
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