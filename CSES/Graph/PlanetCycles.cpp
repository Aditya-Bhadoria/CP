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
 
class DSU {
    vector<int> parent, size, rank;
public:
    // Constructor: initialize DSU for n elements (1-based indexing)
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    // Optional: create a new set containing only v
    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    // Find the representative with path compression
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    // Union two sets by size
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    // Union two sets by rank
    void uniteByRank(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) parent[a] = b;
            else if (rank[b] < rank[a]) parent[b] = a;
            else{
                parent[b] = a;
                rank[a]++;
            }
        }
    }
    // Get size of the set containing v
    int get_size(int v) {
        return size[find(v)];
    }
    // Get rank of the set containing v
    int get_rank(int v){
        return rank[find(v)];
    }
};
 
void dfs1_scc(int node, vector<int>&vis, vector<vector<int>>&adj, stack<int>&st){
    vis[node] = 1;
    for(auto child : adj[node]){
        if(!vis[child]) dfs1_scc(child, vis, adj, st);
    }
    st.push(node);
}

void dfs2_scc(int node, vint &vis, vint adjT[], vint &ans, int scc){
    vis[node] = 1;
    ans[node] = scc;
    for(auto child : adjT[node]){
        if(!vis[child]) dfs2_scc(child, vis, adjT, ans, scc);
        // ans[child] = scc;
    }
}

vll visited(2e5, 0), destination(2e5), pathlength(2e5, 0);
queue<ll> path;
ll steps = 0;

void dfs(int planet){
    path.push(planet);
    if(visited[planet]){
        steps += pathlength[planet];
        return;
    }
    visited[planet] = true;
    steps++;
    dfs(destination[planet]);
}

void solve() {
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> destination[i];
        destination[i]--;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            steps = 0;
            dfs(i);
            int decrement = 1;
            while(!path.empty()){
                if(path.front() == path.back()){ decrement = 0; }
                pathlength[path.front()] = steps;
                steps -= decrement;
                path.pop();
            }
        }
    }
    for(int i=0; i<n; i++) cout << pathlength[i] << " ";
    cout << endl;
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