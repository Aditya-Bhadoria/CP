#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

const int MAX_N = 2e5 + 5;
const int LOG = 20;
ll a[MAX_N];
ll m[MAX_N][LOG]; // m[i][j] is mini among (i, ..., i + 2^j - 1)

ll query(int L, int R) {
    ll total_sum = 0;
    // Decompose the range [L, R] into disjoint power-of-2 intervals
    for (int k = LOG - 1; k >= 0; k--) {
        if ((1 << k) <= R - L + 1) {
            total_sum += m[L][k];
            L += (1 << k); // Move the left pointer forward past the covered block
        }
    }
    return total_sum;
}

// USE PREFIX SUM, THIS IS JUST TO PRACTICE RMQ !!!

void solve(){
    // 1) read input 
    int n, q; cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> a[i];
        m[i][0] = a[i];
    }
    // 2) preprocessing O(N*(log N))
    int expo = 32 - __builtin_clz(n); // plus 1 for safety
    // can also use LOG directly
    for(int k=1; k<expo; k++){
        for(int i=0; i+(1<<k)-1 < n; i++){
            m[i][k] = m[i][k-1] + m[i+(1<<(k-1))][k-1];
        }
    }
    // 3) answer queries
    for(int i=0; i<q; i++){
        int L, R; cin >> L >> R;
        L--; R--;
        cout << query(L, R) << '\n';
    }
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