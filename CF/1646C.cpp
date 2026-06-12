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

const ll MAXAI = 1e12;

int get_first_bit(ll n){
	return 63 - __builtin_clzll(n);
}

int get_bit_count(ll n){
	return __builtin_popcountll(n);
}

void solve() {
    ll n; cin >> n;
    vll fact;
    ll factorial = 6, number = 4;
    while(factorial <= MAXAI){
        fact.push_back(factorial);
        factorial *= number;
        number++;
    }
    vector<pair<ll, ll>> fact_sum(1 << fact.size());
    fact_sum[0] = {0, 0};
    for(int mask = 1; mask < (1 << fact.size()); mask++){
        ll first_bit = get_first_bit(mask);
        fact_sum[mask].first = fact_sum[mask ^ (1 << first_bit)].first + fact[first_bit];
        fact_sum[mask].second = get_bit_count(mask);
    }
    ll res = get_bit_count(n);
    for(auto i : fact_sum){
        if(i.first <= n){
            res = min(res, i.second + get_bit_count(n - i.first));
        }
    }
    cout << res << "\n";
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