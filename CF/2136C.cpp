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
        int n; cin >> n;
        vector<vint> indx(n+1);
        for(int i=0; i<n; i++){
            int x; cin >> x;
            indx[x].pb(i);
        }
        vector<vint> intv;
        for(int i=1; i <= n; i++){
            auto &p = indx[i];
            for(int j=i; j <= p.size(); j++){
                intv.pb({p[j-i], p[j-1], i});
            }
        }
        int m = intv.size();
        vint lo(m), hi(m), w(m), ans(m+1, 0);
        sort(all(intv), [&](auto &a, auto &b){
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        for(int i=0; i<m; i++){
            hi[i] = intv[i][1];
            w[i] = intv[i][2];
            lo[i] = intv[i][0];
        }
        for(int i=1; i<=m; i++){
            int j = lower_bound(all(hi), lo[i-1]) - hi.begin();
            ans[i] = max(ans[i-1], ans[j] + w[i-1]);
        }
        cout << ans[m] << endl;
    }
    return 0;
}
