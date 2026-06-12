#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    vector<vint> dp(n, vint(2, 0));
    dp[0][1] = 1;
    if(s1[0] != s2[0]) dp[0][0] = 1;
    if(n == 1){ cout << dp[0][0] << endl; return; }
    dp[1][0] = dp[0][0] + (s1[1] != s2[1]);
    dp[1][1] = (s1[0] != s1[1]) + (s2[0] != s2[1]);
    for(int i=2; i<n; i++){
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + (s1[i] != s2[i]);
        dp[i][1] = min(dp[i-2][0],dp[i-2][1]) + (s1[i]!=s1[i-1]) + (s2[i]!=s2[i-1]);
    }
    cout << min(dp[n-1][0], dp[n-1][1]) << endl;
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