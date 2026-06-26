#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    dp[i][i] = 0;
    for(int len=2; len<=n; len++){
        for(int i=0; i+len-1 < n; i++){
            int j = i+len-1;
            for(int k=i; k<j; k++){
                ll temp = dp[i][k] + dp[k+1][j] + pref[j+1]-pref[i];
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }
    cout << dp[0][n-1] << endl;
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