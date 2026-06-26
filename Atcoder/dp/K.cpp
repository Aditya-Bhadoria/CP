#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    vector<bool> dp(k + 1);
    for(int i=1; i<=k; i++) for(int j : a) if(i>=j && !dp[i-j]) dp[i] = 1;
    cout << (dp[k] ? "First" : "Second") << '\n';
    // dp[j] = 1 if the starter at j wins
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