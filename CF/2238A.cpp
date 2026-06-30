#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n, c; cin >> n >> c;
    vint a(n), b(n);
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        ans += a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        ans -= b[i];
    }
    vint a2 = a, b2 = b;
    sort(a2.begin(), a2.end());
    sort(b2.begin(), b2.end());
    for(int i=0; i<n; i++){
        if(a2[i] < b2[i]){
            cout << "-1\n"; return;
        }
    }
    bool check = true;
    for(int i=0; i<n; i++){
        if(a[i] < b[i]){
            check = false; break;
        }
    }
    if(check) cout << ans << '\n';
    else cout << ans + c << '\n';
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