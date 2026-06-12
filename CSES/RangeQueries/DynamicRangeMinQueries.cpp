#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

vint tree;
int f(int node, int node_low, int node_high, int q_low, int q_high){
    if(q_low <= node_low && node_high <= q_high){
        return tree[node];
    }
    if(node_high < q_low || q_high < node_low){
        return 1e9;
    }
    int mid = (node_low + node_high)/2;
    return min(f(2*node, node_low, mid, q_low, q_high), 
            f(2*node+1, mid+1, node_high, q_low, q_high));
}

void update(int idx, int v, int n){
    tree[n+idx] = v;
    for(int i=(n+idx)/2; i>=1; i/=2){
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
}

void solve(){
    int n, q; cin >> n >> q;
    vint a(n); 
    for(int i=0; i<n; i++) cin >> a[i];
    while(__builtin_popcount(n) != 1){
        a.push_back(1e9);
        n++;
    }
    tree.resize(2*n);
    for(int i=0; i<n; i++){
        tree[i+n] = a[i];
    }
    for(int i=n-1; i>=1; i--){
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int idx, v; cin >> idx >> v;
            idx--;
            update(idx, v, n);
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