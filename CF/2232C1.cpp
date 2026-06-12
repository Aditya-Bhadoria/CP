#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n, x, s; cin >> n >> x >> s;
    string u; cin >> u;
    vint dp(x+1, -1);
    dp[0] = 0;
    for(int i=0; i<n; i++){
        vint dp2 = dp;
        for(int j=0; j <= min(i, x); j++){
            if(dp[j] == -1) continue;
            if((u[i] == 'I' || u[i] == 'A') && (j<x)){
                dp2[j+1] = max(dp2[j+1], dp[j]+1);
            }
            if((u[i] == 'E' || u[i] == 'A') && (j*s > dp[j])){
                dp2[j] = max(dp2[j], dp[j] + 1);
            }
        }
        dp = dp2;
    }
    int ans = 0;
    for(int j=0; j<=x; j++) ans = max(ans, dp[j]);
    cout << ans << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}