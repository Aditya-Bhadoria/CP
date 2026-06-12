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
    ll pref = 1;
    while (b) {
        if (b & 1) pref *= a;
        b >>= 1;
        a *= a;
    }
    return pref;
}

ll pow(ll a, ll b, ll c) {
    ll pref = 1;
    while (b) {
        if (b & 1) pref = (pref * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return pref;
}

void solve() {
    int n, q; cin >> n >> q;
    vll arr(n); in(arr);
    vll pref(n+1, 0), ind2(n+1, n), ind3(n+1, n);
    for(int i=0; i<n; i++){
        ll temp = arr[i], ok = 0;
        while(temp >= 2){
            temp /= 2; ok++;
            if(temp == 1) break;
            temp++;
        }
        pref[i+1] = ok;
    }
    for(int i=1; i<=n; i++){
        pref[i] += pref[i-1];
    }
    for(int i=n-1; i>=0; i--){
        ind2[i] = ind2[i+1];
        ind3[i] = ind3[i+1];
        if(arr[i] == 2) ind2[i] = i;
        if(arr[i] == 3) ind3[i] = i;
    }
    while(q--){
        int l, r; cin >> l >> r;
        l--; r--;
        ll ans = pref[r+1] - pref[l];
        bool check2 = (ind2[l] <= r), check3 = (ind3[l] <= r);
        
        if(check2 && check3) ans++;
        cout << ans << endl;
    }
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