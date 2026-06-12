#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

ll dp[20][11][2][2];
string s;
ll calc(int idx, int last_dig, bool lead_z, bool tight) {
    // Base case: successfully built a valid number
    if (idx == s.length()) return 1;
    
    if (dp[idx][last_dig][lead_z][tight] != -1) 
        return dp[idx][last_dig][lead_z][tight];

    ll ans = 0;
    // If tight, we can't exceed the digit in our limit string 's'
    int limit = tight ? (s[idx] - '0') : 9;
    for (int d = 0; d <= limit; d++) {
        // Core rule: no adjacent identical digits (unless they are leading zeroes)
        if (!lead_z && d == last_dig) continue;
        bool nxt_lead_z = lead_z && (d == 0);
        bool nxt_tight = tight && (d == limit);

        // If we are still placing leading zeroes, don't register '0' as the last digit
        int nxt_last = nxt_lead_z ? 10 : d; // doesn't matter actually, can send 0/d too
        ans += calc(idx + 1, nxt_last, nxt_lead_z, nxt_tight);
    }
    return dp[idx][last_dig][lead_z][tight] = ans;
}

ll solve_range(ll n) {
    if (n < 0) return 0;
    s = to_string(n);
    memset(dp, -1, sizeof(dp));
    // Start at index 0, dummy last digit 10, leading zero is true, tight is true
    return calc(0, 10, 1, 1);
}

void solve() {
    ll a, b; cin >> a >> b;
    cout << solve_range(b) - solve_range(a - 1) << endl;
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