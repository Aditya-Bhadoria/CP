#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
using namespace __gnu_pbds;
using ll = long long;
using ull=unsigned long long;
 
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pii pair<int,int>
#define pb push_back
#define out(v) for(auto &i: v) cout<<i<<" ";cout << endl;
#define in(v) for(auto &i: v) cin>>i;
#define inn(v,n) for(int i=0;i<n;i++) cin>>v[i];
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
 
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
typedef tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
//p.find_by_order - value at given index
//p.order_of_key - index of given key
 
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a*b/gcd(a,b); }
 
ll pow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}
 
ll pow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}
 
ll factorial(ll x){
    if(x == 1 || x == 0){
        return 1;
    }
    ll ans = 1;
    for(int i=2; i<=x; i++){
        ans = (ans%mod)*(i%mod);
        ans %= mod;
    }
    return ans;
}
 
vint topoSort(int V, vector<vint>& edges){
    vector<vint> adj(V);
    vint indeg(V, 0), ans;
    for(auto &it : edges){
        adj[it[0]].push_back(it[1]);
        indeg[it[1]]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<V; i++){
        if(indeg[i] == 0) pq.push(i);
    }
    while(!pq.empty()){
        int node = pq.top(); pq.pop();
        ans.push_back(node);
        for(auto child : adj[node]){
            indeg[child]--;
            if(indeg[child] == 0) pq.push(child);
        }
    }
    return ans;
}
 
void solve() {
    // Optimised Dijkstra

    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> g[n];
    vll dist(n, 1e18), vis(n, 0);
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
    }
    using T = pair<ll, ll>;
    priority_queue <T, vector<T>, greater<T>> q;
    q.push({0, 0});
    dist[0] = 0;
    while(!q.empty()){
        ll dis = q.top().first;
        ll par = q.top().second;
        q.pop();
        if(vis[par]) continue;
        vis[par] = 1;
        for(auto it : g[par]){
            if(dis + it.second < dist[it.first]){
                dist[it.first] = dis + it.second;
                q.push({dist[it.first], it.first});
            }
        }
    }
    out(dist);
}
 
int main() {
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
 
