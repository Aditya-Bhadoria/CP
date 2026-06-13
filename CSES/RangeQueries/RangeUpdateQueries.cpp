#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

vector<long long> tree;

void update(int node, int node_left, int node_right, int query_left, int query_right, int val) {
    if(node_left >= query_left && node_right <= query_right) {
        tree[node] += val;
        return;
    } 
    else if(node_left > query_right || node_right < query_left) return;
    int mid = (node_left + node_right) / 2;
    update(2 * node, node_left, mid, query_left, query_right, val);
    update(2 * node + 1, mid + 1, node_right, query_left, query_right, val);
}

long long f(int node, int node_left, int node_right, int query_left, int query_right) {
    if(node_left >= query_left && node_right <= query_right) return tree[node];
    else if(node_left > query_right || node_right < query_left) return 0;
    int mid = (node_left + node_right) / 2;
    return f(2 * node, node_left, mid, query_left, query_right) + f(2 * node + 1, mid + 1, node_right, query_left, query_right) + tree[node];
}

void solve(){
    int n, q; cin >> n >> q; vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    while(__builtin_popcount(n) != 1) {
        n++;
        v.push_back(0);
    }
    tree.resize(2 * n);
    for(int i = 0; i  <n; i++) tree[n+i] = v[i];
    for(int i = 0; i < q; i++) {
        int x; cin >> x; 
        if(x == 1) {
            int a, b, u; cin >> a >> b >> u;
            a--; b--;
            update(1, 0, n-1, a, b, u);
        }
        else {
            int k; cin >> k; k--;
            cout << f(1, 0, n-1, k, k) << '\n'; 
        }
    }
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