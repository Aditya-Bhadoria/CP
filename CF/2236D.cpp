#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n, k; cin >> n >> k;
    vint arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    vint v, f;
    v.push_back(arr[0]);
    f.push_back(1);
    for(int i=1; i<n; i++){
        if(arr[i] != arr[i-1]){
            v.push_back(arr[i]);
            f.push_back(1);
        }
        else f.back()++;
    }
    n = v.size();
    int r = n-1, cnt = 0;
    vint dp(n, 0);
    for(int i=n-1; i>=0; i--){
        while(r > i && v[r] > v[i]+k){
            if(dp[r] == 0) cnt--;
            r--;
        }
        if(cnt) dp[i] = 1;
        else dp[i] = ((f[i] - 1) % 2 != 0);
        if(dp[i] == 0) cnt++;
        if(dp[i]){
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
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