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
const int MAXN = 300000 + 5;
const ll P = 998244353;
vll fac(MAXN, 0), invv(MAXN, 0);

void factorials() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fac[i] = fac[i - 1] * i % P;
    }
    invv[MAXN - 1] = pow(fac[MAXN - 1], P - 2, P);
    for (int i = MAXN - 2; i >= 0; --i) {
        invv[i] = invv[i + 1] * (i + 1) % P;
    }
}

ll choose(ll n, ll r) {
    return fac[n] * invv[r] % P * invv[n - r] % P;
}

void solve() {
    factorials();

    int n; cin >> n;
    vll arr(n); in(arr);

    ll ans = choose(n/3, n/6);
    for(int i=0; i<n; i+=3){
        vll temp = {arr[i], arr[i+1], arr[i+2]};
        sort(all(temp));
        if(temp[0] == temp[1] && temp[1] == temp[2]){
            ans = (ans * 3LL) % P;
        } 
        else if(temp[0] == temp[1]){
            ans = (ans * 2LL) % P;
        }
    }
    cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}