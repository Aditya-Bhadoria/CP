#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

// mask = bitset of women (matched/available)
// Normally dp[i][mask] = first i men with subset of women in mask
// But i = number of set bits in mask, so no need for i, __builtin_popcount(mask)

constexpr int MOD = 1e9 + 7;
int compat[22][22];
int dp[1 << 21];

void solve() {
    int n; cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> compat[i][j];
    }
    dp[0] = 1; // Base Case
    // Traverse all subsets of women
    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == 0) continue;
        // Current man to be matched matches the number of active women in mask
        int i = __builtin_popcount(mask);
        // Try pairing Man i with an available Woman j
        for(int j=0; j<n; j++){
            if(compat[i][j] && !(mask & (1 << j))){
                int next_mask = mask | (1 << j);
                dp[next_mask] = (dp[next_mask] + dp[mask]) % MOD;
            }
        }
    }
    cout << dp[(1 << n)-1]; // when all matched
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