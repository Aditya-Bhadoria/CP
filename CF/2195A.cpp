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

void solve() {
    int n; 
    cin >> n;

    vector<array<ll,4>> f(n); 

    for(int i = 0; i < n; i++){
        cin >> f[i][0] >> f[i][1] >> f[i][2];
        f[i][3] = i;
    }

    auto has_edge = [&](array<ll,4> &u, array<ll,4> &v){
        ll da = u[0] - v[0];
        ll db = u[1] - v[1];
        ll dc = u[2] - v[2];

        if(da > 0) return 4LL * da * dc > db * db;
        if(da == 0) return (db == 0 && dc > 0);
        return false;
    };


    sort(all(f), [&](auto &x, auto &y){
        if(x[0] != y[0]) return x[0] > y[0];
        if(x[2] != y[2]) return x[2] > y[2];
        return x[1] > y[1];
    });

    vint dp_in(n, 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(has_edge(f[j], f[i])){
                dp_in[i] = max(dp_in[i], dp_in[j] + 1);
            }
        }
    }

    vint dp_out(n, 1);

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            if(has_edge(f[i], f[j])){
                dp_out[i] = max(dp_out[i], dp_out[j] + 1);
            }
        }
    }

    vint ans(n);

    for(int i = 0; i < n; i++){
        ans[f[i][3]] = dp_in[i] + dp_out[i] - 1;
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}