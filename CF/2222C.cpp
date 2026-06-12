#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n; cin >> n;
    vint a(n);
    for(int i=0; i<n; i++) cin >> a[i]; 
    vint a2 = a;
    sort(a2.begin(), a2.end());
    int med = a2[n/2];
    vint pref1(n+1, 0), pref2(n+1, 0);
    for(int i=0; i<n; i++){
        pref1[i+1] = pref1[i] + (a[i] >= med ? 1 : -1);
        pref2[i+1] = pref2[i] + (a[i] <= med ? 1 : -1);
    }
    vint dp(n+1, -1);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(dp[j] != -1 && (i-j) % 2 == 1){
                if(pref1[i] > pref1[j] && pref2[i] > pref2[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
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
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}