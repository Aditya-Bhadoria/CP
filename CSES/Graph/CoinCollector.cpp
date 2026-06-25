#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

int n, m;
vector<ll> coins;
vector<vector<int>> g, gr, cond_g;
vector<int> vis, order, comp;
vector<ll> comp_coins, dp;

// Topological Sort order
void dfs1(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) dfs1(v);
    }
    order.push_back(u);
}

// extract components
void dfs2(int u, int c) {
    vis[u] = 1;
    comp[u] = c;
    comp_coins[c] += coins[u]; // Accumulate coins inside this mega-node
    for(int v : gr[u]) if(!vis[v]) dfs2(v, c);
}

// calculate max
ll coin(int u) {
    if(dp[u] != -1) return dp[u];
    ll max_next = 0;
    for(int v : cond_g[u]){
        max_next = max(max_next, coin(v));
    }
    return dp[u] = comp_coins[u] + max_next;
}

void solve() {
    cin >> n >> m;
    coins.resize(n);
    g.resize(n);
    gr.resize(n);
    for(int i=0; i<n; i++) cin >> coins[i];
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        gr[v].push_back(u); // Reversed graph
    }
    // Run Pass 1
    vis.assign(n, 0);
    for(int i=0; i<n; i++) if(!vis[i]) dfs1(i);

    // Run Pass 2
    vis.assign(n, 0);
    comp.resize(n);
    comp_coins.assign(n, 0);
    reverse(order.begin(), order.end());

    int comp_cnt = 0;
    for(int u : order){
        if(!vis[u]){
            dfs2(u, comp_cnt);
            comp_cnt++;
        }
    }
    // condensation DAG
    cond_g.resize(comp_cnt);
    for(int u=0; u<n; u++){
        for(int v : g[u]){
            if(comp[u] != comp[v]){
                cond_g[comp[u]].push_back(comp[v]);
            }
        }
    }
    // Evaluate max paths globally across components
    dp.assign(comp_cnt, -1);
    ll ans = 0;
    for(int i=0; i<comp_cnt; i++) ans = max(ans, coin(i));
    cout << ans;
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