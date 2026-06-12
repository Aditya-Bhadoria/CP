#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

vector<ll> tree;
ll f(int node, int node_low, int node_high, int q_low, int q_high){
    if(q_low <= node_low && node_high <= q_high){
        return tree[node];
    }
    if(node_high < q_low || q_high < node_low){
        return 0;
    }
    int mid = (node_high + node_low)/2; // rightmost child in left subtree
    return f(2*node, node_low, mid, q_low, q_high) + 
         f(2*node+1, mid+1, node_high, q_low, q_high);
}

// Iterative
void update(int idx, ll v, int n){ 
    tree[n+idx] = v;
    for(int i=(n+idx)/2; i>=1; i/=2){
        tree[i] = tree[2*i]+tree[2*i+1];
    }
}

// Recursive
void update2(int node, int node_low, int node_high, int q_low, int q_high, int v){
    if(q_low <= node_low && node_high <= q_high){
        tree[node] = v; // I am a leaf
        return;
    }
    if(node_high < q_low || q_high < node_low){
        return;
    }
    int mid = (node_high + node_low)/2; // rightmost child in left subtree
    update2(2*node, node_low, mid, q_low, q_high, v);
    update2(2*node+1, mid+1, node_high, q_low, q_high, v);
    tree[node] = tree[2*node]+tree[2*node+1];
}

void solve(){
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // pad a[] with 0 to make size a power of 2
    while(__builtin_popcount(n) != 1){
        a.push_back(0);
        n++;
    }
    // build tree
    tree.resize(2*n);
    for(int i=0; i<n; i++){
        tree[n+i] = a[i];
    }
    for(int i=n-1; i>=1; i--){
        tree[i] = tree[2*i] + tree[2*i+1];
        // add, min, max, xor anything
    }
    for(int i=0; i<q; i++){
        int type; cin >> type;
        if(type == 1){
            ll idx, v; cin >> idx >> v;
            idx--;
            // update(idx, v, n);
            update2(1, 0, n-1, idx, idx, v);
        }
        else{
            int L, R; cin >> L >> R;
            L--; R--;
            cout << f(1, 0, n-1, L, R) << '\n';
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