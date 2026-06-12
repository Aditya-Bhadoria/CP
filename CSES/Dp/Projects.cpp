#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n; cin >> n;
    vector<vint> a(n, vint(3));
    vint ends(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2]; // start, end, reward
    }
    sort(a.begin(), a.end(), [](auto &x, auto &y) {
        return x[1] < y[1];
    });
    for (int i = 0; i < n; i++) ends[i] = a[i][1];

    vll dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int j = lower_bound(ends.begin(), ends.begin() + i, a[i][0]) - ends.begin();
        dp[i + 1] = max(dp[i], dp[j] + a[i][2]);
    }
    cout << dp[n] << endl;
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