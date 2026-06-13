#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

int n;
vector<vint> g;
vll sub_size, dist_sum, ans;

void dfs_down(int u, int p) {
    sub_size[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs_down(v, u);
        sub_size[u] += sub_size[v];
        dist_sum[u] += dist_sum[v] + sub_size[v];
    }
}

void dfs_up(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        ans[v] = ans[u] + n - 2*sub_size[v];
        dfs_up(v, u);
    }
}

void solve() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    sub_size.assign(n + 1, 0);
    dist_sum.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs_down(1, 0);
    ans[1] = dist_sum[1]; 
    dfs_up(1, 0);
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << '\n';
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