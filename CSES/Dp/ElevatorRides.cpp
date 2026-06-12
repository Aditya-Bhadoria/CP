#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n, x; cin >> n >> x;
    vint a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // dp[mask] = {min_rides, min_weight_of_last_ride}
    vector<pair<int, int>> dp(1 << n, {n + 1, 0});
    // Base case: 0 people need 1 empty ride of weight 0
    dp[0] = {1, 0};
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            // If the i-th person is NOT in the current mask
            if ((mask & (1 << i)) == 0) {
                auto [rides, weight] = dp[mask];

                // Try adding them to the current ride
                if (weight + a[i] <= x) weight += a[i];

                // If they exceed the limit, start a brand new ride
                else {
                    rides++;
                    weight = a[i];
                }
                // Update the state that includes this new person
                int next_mask = mask | (1 << i);
                dp[next_mask] = min(dp[next_mask], {rides, weight});
            }
        }
    }

    // The answer is the minimum rides for the state where all 'n' bits are set to 1
    cout << dp[(1 << n) - 1].first << "\n";
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