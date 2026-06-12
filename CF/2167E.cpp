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

bool check(ll T, int n, int k, ll x, vll a){
    if(T == 0) return x+1 >= k;
    vector<pair<ll, ll>> v;
    for(int i=0; i<n; i++){
        ll l = max(0LL, a[i]-T+1), r = min(x, a[i]+T-1);
        if(l <= r) v.push_back({l, r});
    }
    if(v.empty()) return x+1 >= k;
    sort(all(v));
    ll tot = 0, l = v[0].first, r = v[0].second;
    for(int i=1; i<v.size(); i++){
        if(v[i].first <= r+1) r = max(r, v[i].second);
        else{
            tot += r-l+1;
            l = v[i].first;
            r = v[i].second;
        }
    }
    tot += r-l+1;
    return x-tot+1 >= k;
}

void solve() {
    ll n, k, x; cin >> n >> k >> x;
    vll a(n); in(a);
    ll l = 0, r = x+1, ans = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(mid, n, k, x, a)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }

    vector<pair<ll, ll>> v;
    if(ans > 0){
        for(int i=0; i<n; i++){
            ll l = max(0LL, a[i]-ans+1), r = min(x, a[i]+ans-1);
            if(l <= r) v.push_back({l, r});
        }
    }
    vector<pair<ll, ll>> merged;
    if(!v.empty()){
        sort(all(v));
        ll l = v[0].first, r = v[0].second;
        for(int i=1; i<v.size(); i++){
            if(v[i].first <= r+1) r = max(r, v[i].second);
            else{
                merged.push_back({l, r});
                l = v[i].first;
                r = v[i].second;
            }
        }
        merged.push_back({l, r});
    }
    int cnt = 0;
    ll last = -1;
    for(auto &p : merged){
        for(ll i = last+1; i<p.first; i++){
            if(cnt == k) break;
            cout << i << " ";
            cnt++;
        }
        if(cnt == k) break;
        last = p.second;
    }
    for(ll i = last+1; i<=x && cnt<k; i++){
        cout << i << " ";
        cnt++;
    }
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