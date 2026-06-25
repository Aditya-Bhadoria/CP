#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>
constexpr int MAXN = 2e5 + 5;
int up[MAXN][30];
int LOG;

int f(int v, int k){
    for(int j=LOG-1; j>=0; j--){
        if(k>=(1<<j)){
            v = up[v][j];
            k -= (1<<j);
        }
    }
    return v;
}

void solve(){
    int n, q; cin >> n >> q;
    LOG = 30;
    // up.assign(n, vint(LOG));
    for(int i=0; i<n; i++){
        int x; cin >> x;
        x--;
        up[i][0] = x;
    }
    for(int j=1; j<LOG; j++){
        for(int v=0; v<n; v++){
            up[v][j] = up[up[v][j-1]][j-1];
        }
    }
    while(q--){
        int v, k; cin >> v >> k;
        cout << f(--v, k)+1 << '\n';
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