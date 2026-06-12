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

vint seg_tree;
int tree_size;

void build(int n) {
    tree_size = n;
    seg_tree.assign(4 * n, 0);
}

void update(int node, int l, int r, int pos, int val) {
    if (l == r) {
        seg_tree[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(node * 2, l, mid, pos, val);
    else update(node * 2 + 1, mid + 1, r, pos, val);
    seg_tree[node] = max(seg_tree[node * 2], seg_tree[node * 2 + 1]);
}

int query(int node, int l, int r, int ql, int qr) {
    if (ql > qr) return 0;
    if (l == ql && r == qr) return seg_tree[node];
    int mid = (l + r) / 2;
    return max(query(node * 2, l, mid, ql, min(qr, mid)),
               query(node * 2 + 1, mid + 1, r, max(ql, mid + 1), qr));
}

void solve() {
    int n; cin >> n;
    vint a(n); in(a);
    int mx = *max_element(all(a));
    build(mx);

    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        int val = a[i], bad = val - 1;
        int left = query(1, 1, mx, 1, bad - 1);
        int right = query(1, 1, mx, bad + 1, mx);
        int new_len = 1 + max(left, right);
        update(1, 1, mx, val, new_len);
        max_len = max(max_len, new_len);
    }

    cout << n - max_len << "\n";
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