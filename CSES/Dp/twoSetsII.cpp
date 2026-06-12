#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    ll total_sum = 1LL * n * (n + 1) / 2;
    if(total_sum % 2 != 0){
        cout << "0\n"; return;
    }
    int target = total_sum / 2;
    int MOD = 1e9 + 7;

    // dp[w] stores the number of ways to make sum w
    vint dp(target + 1, 0);
    dp[0] = 1; // 1 way to make sum 0 (pick nothing)
    // Only iterate up to n - 1 to handle the symmetry trick
    for (int i = 1; i < n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    cout << dp[target] << endl;
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