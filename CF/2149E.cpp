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
    int n, k, l, r; cin >> n >> k >> l >> r;
    vll a(n); in(a);

    map<ll,ll> mp;
    int num = 0, lk = 0;
    ll ans = 0;
    for(int i=0; i<n; i++){
        if(mp[a[i]] == 0) num++;
        mp[a[i]]++;

        while(num > k){
            mp[a[lk]]--;
            if(mp[a[lk]] == 0){
                mp.erase(a[lk]);
                num--;
            }
            lk++;
        }
        ll mini = max(lk, i-r+1), maxi = i-l+1;
        if(mini <= maxi) ans += ll(maxi-mini+1);
    }
    k--;
    map<ll,ll> mp1;
    int num1 = 0, lk1 = 0;
    for(int i=0; i<n; i++){
        if(mp1[a[i]] == 0) num1++;
        mp1[a[i]]++;

        while(num1 > k){
            mp1[a[lk1]]--;
            if(mp1[a[lk1]] == 0){
                mp1.erase(a[lk1]);
                num1--;
            }
            lk1++;
        }
        ll mini = max(lk1, i-r+1), maxi = i-l+1;
        if(mini <= maxi) ans -= ll(maxi-mini+1);
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}