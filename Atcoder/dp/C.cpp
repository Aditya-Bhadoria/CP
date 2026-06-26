#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    // dp[i][0] = max(dp[i-1][1] + b[i-1], dp[i-1][2] + c[i-1]);
    // dp[i][1] = max(dp[i-1][0] + a[i-1], dp[i-1][2] + c[i-1]);
    // dp[i][2] = max(dp[i-1][0] + a[i-1], dp[i-1][1] + b[i-1]);
    // ans = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
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