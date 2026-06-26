#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

vector<vll> mat_mult(const vector<vll>& A, const vector<vll>& B) {
    ll N = A.size();
    vector<vll> C(N, vll(N, 0));
    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < N; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    return C;
}
vector<vll> mat_pow(vector<vll> base, ll power) {
    ll N = base.size();
    vector<vector<ll>> result(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) result[i][i] = 1;

    while (power > 0) {
        if (power & 1) result = mat_mult(result, base);
        base = mat_mult(base, base);
        power >>= 1;
    }
    return result;
}

void solve(){
    // nomral bin exp mat mult
    vector<vll> ans = mat_pow(mat, k);
    ll res = 0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) res = (res+ans[i][j])%mod;
    cout << res << endl;
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