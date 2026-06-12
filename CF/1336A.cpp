#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

vint depth, sz, diff;
void dfs(int node, int par, vint g[]){
    if(par != -1) depth[node] = depth[par]+1;
    for(auto it : g[node]){
        if(it == par) continue;
        dfs(it, node, g);
        sz[node] += (1+sz[it]);
    }
    diff[node] = sz[node]-depth[node];
}
void solve(){
    int n, k; cin >> n >> k;
    depth.assign(n, 0);
    sz.assign(n, 0);
    diff.assign(n, 0);
    vint g[n+1];
    for(int i=1; i<n; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, g);
    sort(diff.rbegin(), diff.rend());
    ll ans = 0;
    for(int i=0; i<n-k; i++) ans += diff[i];
    cout << ans << endl;
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