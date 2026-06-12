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
void dfs(int i, vint g[], vint &vis){
    vis[i] = 1;
    for(auto it : g[i]){
        if(!vis[it]) dfs(it, g, vis);
    }
}
void solve(){
    int n, m; cin >> n >> m;
    vint g[n+1], par(n+1, -1), dist(n+1, 1e9), ans;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        g[x].pb(y); g[y].pb(x);
    }
    using T = int;
    priority_queue<T, vector<T>, greater<T>> q;
    dist[1] = 0; q.push(1);
    while(!q.empty()){
        int x = q.top(); q.pop();
        for(auto it : g[x]){
            if(dist[x] + 1 < dist[it]){
                dist[it] = dist[x] + 1;
                par[it] = x;
                q.push(it);
            }
        }
    }
    if(dist[n] == 1e9){ cout << "IMPOSSIBLE\n"; return; }
    while(n != -1){
        ans.pb(n);
        n = par[n];
    }
    cout << ans.size() << endl;
    reverse(all(ans)); out(ans);
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
 
