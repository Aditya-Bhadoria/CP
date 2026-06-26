#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

int n;
vector<ll> tree;

// Point Update: Insert the new DP beauty score at the flower's height index
void update(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val);
    else update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

// Range Maximum Query: Query the maximum beauty achieved in the height range [l, r]
ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0; // Completely outside the range
    if (l <= start && end <= r) return tree[node]; // Completely inside the range
    
    int mid = (start + end) / 2;
    return max(query(2 * node, start, mid, l, r), 
               query(2 * node + 1, mid + 1, end, l, r));
}

void solve() {
    cin >> n;
    vll h(n), a(n);
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<n; i++) cin >> a[i];

    // Segment tree array size requires 4 * N allocated slots
    tree.assign(4 * n + 5, 0);
    ll ans = 0;
    for(int i=0; i<n; i++){
        // Query the range of heights strictly smaller than the current flower: [1, h[i] - 1]
        ll max_prev = query(1, 1, n, 1, h[i] - 1);
        ll cur_dp = max_prev + a[i];
        ans = max(ans, cur_dp);
        // Push the calculated optimal DP score into the tree at position h[i]
        update(1, 1, n, h[i], cur_dp);
    }
    cout << ans << "\n";
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