#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

const int N = 2e5 + 5;
const int LOG = 20;
int a[N];
int m[N][LOG];

int query(int L, int R){
    int xor_sum = 0;
    for(int k=LOG-1; k>=0; k--){
        if((1<<k) <= R-L+1){
            xor_sum ^= m[L][k];
            L += (1<<k);
        }
    }
    return xor_sum;
}

// USE XOR PREFIX SUM, THIS IS ONLY TO PRACTICE RMQ

void solve(){
    int n, q; cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> a[i];
        m[i][0] = a[i];
    }
    int expo = 32 - __builtin_clz(n);
    for(int k=1; k<expo; k++){
        for(int i=0; i+(1<<k)-1 < n; i++){
            m[i][k] = m[i][k-1] ^ m[i+(1<<(k-1))][k-1];
        }
    }
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