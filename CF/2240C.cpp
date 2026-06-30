#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n; cin >> n;
    vll a(n);
    ll cnt = 0, xori = 0, ans = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]) cnt++;
        xori ^= a[i];
    }
    if(cnt <= 1){ cout << "0\n"; return; }
    if(!xori){ cout << "1\n"; return; }
    for(int i=0; i<n; i++){
        if((xori^a[i]) <= a[i]) ans++;
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