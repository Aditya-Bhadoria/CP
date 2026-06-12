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

map<ll, ll> dp_map;

ll query_dp(ll idx){
    auto it = dp_map.upper_bound(idx);
    if(it != dp_map.begin()){
        it--;
        return it->second;
    }
    return 0;
}

void update_dp(ll idx, ll val){
    auto it = dp_map.upper_bound(idx);
    if(it != dp_map.begin()){
        it--;
        if(it->second >= val) return;
    }
    it = dp_map.find(idx);
    if(it != dp_map.end() && it->second >= val) return;
    dp_map[idx] = val;
    it = dp_map.find(idx);
    it++;
    while(it != dp_map.end() && it->second <= val) it = dp_map.erase(it);
}

void solve(){
    int n; cin >> n;
    vll a(n), c(n); in(a); in(c);
    ll tot = 0, maxi = 0;
    tot = accumulate(all(c), 0LL);
    dp_map.clear();
    dp_map[0] = 0;
    for(int i=0; i<n; i++){
        ll prev_max = query_dp(a[i]);
        ll dp_i = c[i] + prev_max;
        update_dp(a[i], dp_i);
        maxi = max(maxi, dp_i);
    }
    cout << tot - maxi << endl;
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