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
 
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n);
    for(int i=0; i<m; i++){
        ll x, y, c; cin >> x >> y >> c;
        x--; y--;
        adj[x].push_back({y, c});
    }

    const ll INF = 1e18;
    vll dist(n, INF), ways(n, 0), mini(n, INF), maxi(n, -INF);
    dist[0] = 0; ways[0] = 1;
    mini[0] = 0; maxi[0] = 0;

    using T = pair<ll,ll>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        for(auto [v,w] : adj[u]){
            if(d + w < dist[v]){
                dist[v] = d + w;
                ways[v] = ways[u];
                mini[v] = mini[u] + 1;
                maxi[v] = maxi[u] + 1;
                pq.push({dist[v], v});
            }
            else if(d + w == dist[v]){
                ways[v] = (ways[v] + ways[u]) % mod;
                mini[v] = min(mini[v], mini[u] + 1);
                maxi[v] = max(maxi[v], maxi[u] + 1);
            }
        }
    }
    cout <<dist[n-1]<<" "<<ways[n-1]<<" "<<mini[n-1]<<" "<<maxi[n-1];
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
