#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void dfs(int node, int par, vint g[], vint &vis, int &ans){
    for(auto it : g[node]){
        if(it == par) continue;
        dfs(it, node, g, vis, ans);
        if(!vis[it] && !vis[node]){
            vis[it] = 1; vis[node] = 1;
            ans++;
        }
    }
}

void solve(){
    int n; cin >> n;
    vint g[n+1], vis(n+1, 0);
    int ans = 0;
    for(int i=0; i<n-1; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, g, vis, ans);
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