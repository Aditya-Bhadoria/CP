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

class DSU {
    vector<int> parent, size, rank;
public:
    // Constructor: initialize DSU for n elements (1-based indexing)
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
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
    // Get size of the set containing v
    int get_size(int v) {
        return size[find(v)];
    }
};

bool dfs(int u, int parent, vector<set<ll>>& g, vll& color) {
    for (auto v : g[u]) {
        if (v == parent) continue; // Skip the edge to parent
 
        if (color[v] == -1) {
            color[v] = 1 - color[u]; // Alternate color
            if (dfs(v, u, g, color)) return true; // Recursive DFS
        }
        else if (color[v] == color[u]) {
            // Same color on both sides ⇒ Odd-length cycle
            return true;
        }
    }
    return false;
}
 
 
void solve(){
    int n;
    cin>>n;
    vector<set<ll>> g(n+1);
    vll hash(n+1,0);
    int f=0;
    for(int i=0 ; i<n ; i++){
        int v1,v2;
        cin>>v1>>v2;
        if(v1==v2) f=1;
        hash[v1]++;
        hash[v2]++;
        g[v1].insert(v2);
        g[v2].insert(v1);
    }
 
    sort(hash.rbegin(),hash.rend());
    if(hash[0]>2||f){
        cout << "NO\n";
        return;
    }
 
    vll color(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            if (dfs(i, -1, g, color)) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}