#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         if(s[i-1] == t[j-1]){
    //             dp[i][j] = dp[i-1][j-1] + 1;
    //         }
    //         else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    //     }
    //     prev = curr;
    // }
    // can do -> dp[i] = curr, dp[i-1] = prev;
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