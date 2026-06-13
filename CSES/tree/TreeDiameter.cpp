#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

vector<vint> g;
int dist, root;

void dfs(int u, int p, int d) {
    if (d > dist) {
        dist = d;
        root = u;
    }
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

void solve(){
    int n; cin >> n;
    g.assign(n+1, vector<int>());
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dist = -1;
    dfs(1, 0, 0);
    dist = -1;
    dfs(root, 0, 0);
    cout << dist << '\n';
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