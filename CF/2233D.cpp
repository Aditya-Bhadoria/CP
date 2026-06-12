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
    int n; cin >> n;
    vint a(n); in(a);
    int dif = 0;
    for(int i=0; i<n-1; i++){
        if(a[i] != a[i+1]) dif++;
    }
    vint v = a;
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int u = v.size();
    if(dif == u - 1){
        cout << "YES\n"; return;
    }
    if(dif > u+3){
        cout << "NO\n"; return;
    }
    vint ca(n);
    for(int i=0; i<n; i++){
        ca[i] = lower_bound(all(v), a[i]) - v.begin();
    }
    vint fst(u, -1), lst(u, -1), freq(u);
    for(int i=0; i<n; i++){
        int x = ca[i];
        if(fst[x] == -1) fst[x] = i;
        lst[x] = i;
        freq[x]++;
    }
    vector<bool> split(u);
    for(int i=0; i<u; i++){
        if(lst[i]-fst[i]+1 != freq[i]) split[i] = 1;
    }
    set<int> st;
    for(int i=0; i<n; i++){
        if(!split[ca[i]]) continue;
        if(i == 0 || ca[i] != ca[i-1]){
            st.insert(i);
            if(i) st.insert(i-1);
        }
        if(i == n-1 || ca[i] != ca[i+1]){
            st.insert(i);
            if(i < n-1) st.insert(i+1);
        }
    }
    vint c(all(st));
    bool ok = 0;
    for(int i=0; i<c.size() && !ok; i++){
        for(int j=i+1; j<c.size(); j++){
            int p = c[i], q = c[j];
            vint ed;
            if (p-1 >= 0) ed.push_back(p-1);
            if (p < n-1) ed.push_back(p);
            if (q-1 >= 0) ed.push_back(q-1);
            if (q < n-1) ed.push_back(q);
            sort(all(ed));
            ed.erase(unique(all(ed)), ed.end());
            int bef = 0, aft = 0;
            for(auto x : ed){
                if(a[x] != a[x+1]) bef++;
            }
            swap(a[p], a[q]);
            for(auto x : ed){
                if(a[x] != a[x+1]) aft++;
            }
            swap(a[p], a[q]);
            if(dif-bef+aft == u-1){
                ok = 1; break;
            }
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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