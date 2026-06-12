#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
const ll MOD = 1e9 + 7;
vll inv(1e5 + 2);
ll C(ll n, ll r){
    ll res = 1;
    for (int i=1; i<=r; ++i) {
        ll num = (n-r+i) % MOD;
        res = res * num % MOD;
        res = res * inv[i] % MOD;
    }
    return res;
}

int main() {
    inv[1] = 1;
    for(int i=2; i <= 1e5+1; i++){
        inv[i] = (MOD - MOD/i * inv[MOD%i] % MOD) % MOD;
    }
    int t; cin >> t;
    while(t--){
        ll a, b, k; cin >> a >> b >> k;
        ll n = (a-1)*k + 1;
        ll comb = C(n, a), m = (((b-1)%MOD)*(k%MOD))%MOD;
        m = (m*comb + 1)%MOD;
        cout << n%MOD << ' ' << m << '\n';
    }
    return 0;
}