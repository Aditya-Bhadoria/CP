#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    ll n, d; cin >> n >> d;
    vll arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    ll ans = 0, sum = 0, l = n-d, r = d;
    for(int j=-d; j<=d; j++) sum += arr[(j+n) % n];
    for(int i=0; i<n; i++){
        ll cntri = (2LL*d + 1)*arr[i] - sum;
        if(cntri > 0) ans += cntri;
        sum -= arr[l];
        l = (l+1) % n; r = (r+1) % n;
        sum += arr[r];
    }
    cout << ans << '\n';
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