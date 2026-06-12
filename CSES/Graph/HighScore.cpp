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

const ll NEG_INF = -4e18;

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> g[n];
    vector<array<ll,3>> edges; 
    for(int i=0; i<m; i++){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
        edges.push_back({a, b, c});
    }
    vll dist(n, NEG_INF);
    dist[0] = 0;
    for(int i=0; i<n-1; i++){
        for(auto &e : edges){
            ll u = e[0], v = e[1], w = e[2];
            if(dist[u] != NEG_INF && dist[u] + w > dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    out(dist);
    vint affected(n, 0), vis(n, 0);
    for(auto &e : edges){
        ll u = e[0], v = e[1], w = e[2];
        if(dist[u] != NEG_INF && dist[u] + w > dist[v]){
            affected[v] = 1;
        }
    }
    out(dist);
    queue<int> q;
    for(int i=0; i<n; i++){
        if(affected[i]){ q.push(i); vis[i] = 1; }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &p : g[u]){
            int v = p.first;
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    if (vis[n-1]) cout << -1 << "\n"; 
    else cout << dist[n-1] << "\n";
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
