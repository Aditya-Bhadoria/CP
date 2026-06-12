#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    ll a, b, x; cin >> a >> b >> x;
    vll a1, b1;
    for(ll i=a; i>=0; i/=x){
        a1.push_back(i);
        if(!i) break;
    }
    for(ll i=b; i>=0; i/=x){
        b1.push_back(i);
        if(!i) break;
    }
    ll ans = 2e18;
    for(ll i=0; i<a1.size(); i++){
        for(ll j=0; j<b1.size(); j++){
            ans = min(ans, i+j + abs(a1[i]-b1[j]));
        }
    }
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