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

int x = -1, y = -1;
bool dfs(int ver, int par, vint g[], vint &vis){
    vis[ver] = 1;
    bool isPos = false;
    for(auto child : g[ver]){
        if(vis[child] && child == par) continue;
        if(vis[child]){
            y = child, x = ver;
            return true;
        }
        isPos |= dfs(child, ver, g, vis);
    }
    return isPos;
}
void backtrack(int idx, vint g[], vint &dist, vint &ans){
    if(idx == x) return;
    for(auto child : g[idx]){
        if(dist[child] + 1 == dist[idx]){
            ans.push_back(child);
            backtrack(child, g, dist, ans);
            return;
        }
    }
}
void solve(){
    int n, m; cin >> n >> m;
    vint g[n+1], vis(n+1, 0), ans, dist(n+1, 100);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        g[a].pb(b); g[b].pb(a);
    }
    bool check = false;
    for(int i=1; i<=n; i++){
        if(!vis[i] && dfs(i, -1, g, vis)){
            check = true;
            break;
        }
    }
    if(!check){ cout << "IMPOSSIBLE\n"; return; }
    for(int i=0; i<=n; i++) vis[i] = 0;
    dist[x] = 0; vis[x] = 1;
    queue<int> q; q.push(x);
    while(!q.empty()){
        int ok = q.front(); q.pop();
        for(auto child : g[ok]){
            if(ok == x && child == y) continue;
            if(!vis[child]){
                vis[child] = 1;
                dist[child] = dist[ok] + 1;
                q.push(child);
            }
        }
    }
    ans.push_back(y);
    backtrack(y, g, dist, ans);
    ans.push_back(y);
    cout << ans.size() << endl; out(ans);
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
 
