#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

class DSU {
    public:
    vint par, size;
    DSU (int n){
        par.assign(n+1, 0);
        size.assign(n+1, 1);
        for(int i=0; i<=n; i++) par[i] = i;
    }
    int find(int v){
        if(par[v] == v) return v;
        return par[v] = find(par[v]);
    }
    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        if(size[u] >= size[v]){
            par[v] = u;
            size[u] += size[v];
        }
        else{
            par[u] = v;
            size[v] += size[u];
        }
    }
    int get_size(int u){
        return size[find(u)];
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<vll> edges;
    for(int i=0; i<m; i++){
        ll x, y, w; cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    sort(edges.begin(), edges.end(), [&](vll a, vll b){
        return a[2] < b[2];
    });
    DSU ds(n+1);
    ll ans = 0;
    for(int i=0; i<m; i++){
        if(ds.find(edges[i][0]) == ds.find(edges[i][1])) continue;
        ds.unite(edges[i][0], edges[i][1]);
        ans += edges[i][2];
    }
    if(ds.get_size(edges[0][0]) != n){
        cout << "IMPOSSIBLE\n"; return;
    }
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