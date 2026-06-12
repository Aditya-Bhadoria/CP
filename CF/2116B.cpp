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
#define pb push_back
#define out(v) for(auto i: v) cout<<i<<" ";

const ll mod2 = 998244353;
const ll MAX_N = 1e5;
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

vll pow2(1e5+2,1);

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    pow2[0] = 1;
    for(int i=1; i<=1e5; i++){
        pow2[i]=(pow2[i-1]*2)%mod2;
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vll p(n), q(n);
        vll r(n);
        vll mxp(n), mxq(n);
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }
        for (int i = 0; i < n; i++){
            cin >> q[i];
        }
        mxp[0] = 0; mxq[0] = 0;
        for(int i=1; i<n; i++){
            if(p[mxp[i-1]] > p[i]){
                mxp[i] = mxp[i-1];
            }
            else{
                mxp[i] = i;
            }
            if(q[mxq[i-1]] > q[i]){
                mxq[i] = mxq[i-1];
            }
            else{
                mxq[i] = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            ll k = p[mxp[i]];
            ll bk = q[mxq[i]];
            ll mx = max(k, bk), other = 0;
            if(mx == k){
                other = max(other, q[i-mxp[i]]);
            }
            if(mx == bk){
                other = max(other, p[i-mxq[i]]);
            }
            ll val = (pow2[other] + pow2[mx])%mod2;
            r[i] = val;
        }
        
        for (int i = 0; i < n; ++i) {
            cout << r[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}