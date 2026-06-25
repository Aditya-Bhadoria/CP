#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

vector<vint> g;
vint vis, parent;
int cycle_start = -1, cycle_end = -1;

bool dfs(int u) {
    vis[u] = 1; // Mark as currently visiting
    for(int v : g[u]){
        if(vis[v] == 0){
            parent[v] = u;
            if(dfs(v)) return true;
        } 
        else if(vis[v] == 1){ // Found a back-edge (cycle)
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    vis[u] = 2; // Mark as fully processed
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    g.assign(n + 1, vint());
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v); // Directed graph
    }
    for(int i=1; i<=n; i++){
        if(vis[i] == 0 && dfs(i)){
            vint cycle;
            cycle.push_back(cycle_start);
            // Trace back from the end of the cycle to the start
            for(int curr = cycle_end; curr != cycle_start; curr = parent[curr]){
                cycle.push_back(curr);
            }
            cycle.push_back(cycle_start);
            // Reverse to print chronologically
            reverse(cycle.begin(), cycle.end());
            cout << cycle.size() << "\n";
            for(int j=0; j < cycle.size(); j++) cout << cycle[j] << " ";
            cout << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
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