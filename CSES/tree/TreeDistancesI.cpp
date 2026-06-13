#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

vector<vint> g;
int farthest_node, maxi;

void dfs(int u, int p, int d, vint &dist){
    dist[u] = d;
    if (d > maxi) {
        maxi = d;
        farthest_node = u;
    }
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u, d + 1, dist);
        }
    }
}

void solve() {
    int n; cin >> n;
    g.assign(n+1, vector<int>());
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vint dummy(n + 1, 0), distA(n + 1, 0), distB(n + 1, 0);

    maxi = -1;
    dfs(1, 0, 0, dummy);
    int nodeA = farthest_node;

    maxi = -1;
    dfs(nodeA, 0, 0, distA);
    int nodeB = farthest_node;

    maxi = -1;
    dfs(nodeB, 0, 0, distB);

    for(int i=1; i<=n; i++) cout << max(distA[i], distB[i]) << " ";
    cout << "\n";
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