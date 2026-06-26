#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    // dp[i][i] = a[i];
    // for(int len = 1; len < n; len++){
    //     for(int i=0; i<n-len; i++){
    //         int j = i + len;
    //         dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
    //     }
    // }
    // cout << dp[0][n-1];
    // dp[i][j] -> diff X-Y if array was from a[i] to a[j]
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