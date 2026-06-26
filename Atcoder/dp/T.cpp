#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

const int MOD = 1e9 + 7;
// something something
void solve() {
    int n;
    string s;
    if (!(cin >> n >> s)) return;

    // dp[j] stores the number of ways where the last element has relative rank j
    vector<int> dp(n + 1, 0);
    dp[1] = 1; // Base case: 1 element has exactly 1 relative rank

    for (int i = 2; i <= n; i++) {
        // 1) Build prefix sums of the previous row
        vector<int> pref(i, 0);
        for (int j = 1; j < i; j++) {
            pref[j] = (pref[j - 1] + dp[j]) % MOD;
        }

        vector<int> next_dp(i + 1, 0);
        char op = s[i - 2];

        // 2) Transition into the next row using O(1) prefix ranges
        for (int j = 1; j <= i; j++) {
            if (op == '<') {
                // Sum from k = 1 to j-1
                next_dp[j] = pref[j - 1];
            } else {
                // Sum from k = j to i-1
                next_dp[j] = (pref[i - 1] - pref[j - 1] + MOD) % MOD;
            }
        }
        dp = next_dp;
    }

    // Total answer is the sum of all ending relative ranks for length N
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        ans = (ans + dp[j]) % MOD;
    }
    cout << ans << "\n";
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