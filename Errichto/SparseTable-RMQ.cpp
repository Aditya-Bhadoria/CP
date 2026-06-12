#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

const int MAX_N = 1e5 + 5;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is mini among (i, ..., i + 2^j - 1)

int query(int L, int R){
    int len = R-L+1;
    // int k = 0;
    // while((1<<(k+1)) <= len){
    //     k++;
    // }
    int k = 31 - __builtin_clz(len); // True O(1)
    return min(m[L][k], m[R-(1<<k)+1][k]);
}

// min, max, gcd - if data remains same, otherwise segment fucking tree
// NOT sum

void solve(){
    // 1) read input 
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        m[i][0] = a[i];
    }
    // 2) preprocessing O(N*(log N))
    int expo = 32 - __builtin_clz(n); // plus 1 for safety
    // can also use LOG directly
    for(int k=1; k<expo; k++){
        for(int i=0; i+(1<<k)-1 < n; i++){
            m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
        }
    }
    // 3) answer queries
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int L, R; cin >> L >> R;
        cout << query(L, R) << endl;
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