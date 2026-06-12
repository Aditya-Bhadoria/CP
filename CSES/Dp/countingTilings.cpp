#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

const int MOD = 1e9 + 7;
int n, m;
vector<vector<int>> dp;

// Recursively try placing tiles in the current column to generate valid next masks
void generate_masks(int col, int mask, int next_mask, int row) {
    // If we've processed all rows in this column, add the ways to the next state
    if (row == n) {
        dp[col + 1][next_mask] = (dp[col + 1][next_mask] + dp[col][mask]) % MOD;
        return;
    }
    // If the current cell is already occupied by a tile from the previous column
    if ((mask & (1 << row)) != 0) generate_masks(col, mask, next_mask, row + 1);
    else {
        // Option 1: Place a horizontal 1x2 tile (sticks into the next column)
        generate_masks(col, mask, next_mask | (1 << row), row + 1);

        // Option 2: Place a vertical 2x1 tile (takes this row and the next row)
        if (row + 1 < n && (mask & (1 << (row + 1))) == 0) {
            generate_masks(col, mask, next_mask, row + 2);
        }
    }
}

void solve() {
    cin >> n >> m;
    dp.assign(m + 1, vector<int>(1 << n, 0));
    // Base case: 1 way to have 0 columns filled with no tiles sticking out
    dp[0][0] = 1;
    // dp[i][mask], mask represent rows already block by previous col
    for (int i = 0; i < m; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[i][mask] > 0) {
                // Generate all valid placements for the current column
                generate_masks(i, mask, 0, 0);
            }
        }
    }
    // with NO tiles sticking out into the m+1 column
    cout << dp[m][0] << "\n";
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