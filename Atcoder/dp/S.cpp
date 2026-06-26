#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

// dp[len][rem][is_less] = The number of prefixes of length len, 
//                  with digit sum % D = rem, and the restriction flag is_less.
constexpr int MOD = 1e9 + 7;
int dp[100005][105][2]; // dp[len][remainder][is_less]

void solve(){
    string k; cin >> k;
    int d; cin >> d;
    int n = k.length();
    dp[0][0][0] = 1; // Base Case: sum is 0, not "less" than K yet.

    for(int i=0; i<n; i++){
        int curr_dig = k[i] - '0';
        for(int rem=0; rem<d; rem++){
            for(int is_less = 0; is_less <= 1; is_less++){
                if (dp[i][rem][is_less] == 0) continue;

                // Determine the upper bound for the digit at position i
                int limit = is_less ? 9 : curr_dig;

                for (int digit = 0; digit <= limit; digit++) {
                    int next_rem = (rem + digit) % d;
                    int next_is_less = is_less || (digit < limit);
                    dp[i+1][next_rem][next_is_less] = 
                        (dp[i+1][next_rem][next_is_less] + dp[i][rem][is_less]) % MOD;
                }
            }
        }
    }
    ll ans = (dp[n][0][0] + dp[n][0][1]) % MOD;
    // Edge Case: Our DP counts the number 0 as valid (its digit sum is 0, which is 0 % d == 0).
    // The problem asks for numbers from 1 to K, so we must subtract 1.
    ans = (ans-1 + MOD) % MOD;
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