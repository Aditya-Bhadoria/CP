#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

vector<vector<int>> up;
vector<int> depth;
vector<vector<int>> g;
int LOG;

int f(int node, int k){
    for(int j=LOG-1; j>=0; j--){
        if(k >= (1<<j)){
            node = up[node][j];
            k -= (1<<j);
        }
    }
    return node;
}

void dfs(int u, int p) {
    up[u][0] = p;
    for (int v : g[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

void solve(){
    int n, q; cin >> n >> q;
    LOG = 32 - __builtin_clz(n);
    g.assign(n, vector<int>());
    up.assign(n, vector<int>(LOG));
    depth.resize(n);

    for(int i=1; i<n; i++){
        int x; cin >> x;
        x--;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(0, 0);
    // up[v][j] = 2^j th ancestor of node v
    for(int j=1; j<LOG; j++){
        for(int v=0; v<n; v++){
            up[v][j] = up[up[v][j-1]][j-1];
        }
    }
    while(q--){
        int x, k; cin >> x >> k;
        x--;
        if(depth[x] < k) cout << "-1\n";
        else cout << f(x, k)+1 << endl;
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