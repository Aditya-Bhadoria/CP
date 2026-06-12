#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n, m; cin >> n >> m;
    vll a(n), odd, eve;
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        ans += a[i];
        if(i%2 == 0) odd.push_back(a[i]);
        else eve.push_back(a[i]);
    }
    int od = 0, ev = 0;
    for(int i=0; i<m; i++){
        int x; cin >> x;
        if(x%2 != 0) od++;
        else ev++;
    }
    sort(odd.rbegin(), odd.rend());
    sort(eve.rbegin(), eve.rend());

    if(od > 0 && !odd.empty()){
        ans -= odd[0];
        int x = odd.size();
        for(int i=1; i < min(x, od); i++){
            if(odd[i]>0) ans -= odd[i];
            else break; 
        }
    }
    if(ev > 0 && !eve.empty()){
        ans -= eve[0];
        int x = eve.size();
        for(int i=1; i < min(x, ev); i++){
            if(eve[i]>0) ans -= eve[i];
            else break;
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