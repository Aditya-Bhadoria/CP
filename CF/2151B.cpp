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

void black(int x, map<int,int> &byL, map<int,int> &byR){
    auto it = byL.upper_bound(x);
    if(it != byL.begin()){
        it--;
        auto pr = *it;         
        int l = pr.first, r = pr.second;
        if(x >= l && x <= r) return;
    }
    int l = x, r = x;
    auto itR = byR.find(x-1);
    if(itR != byR.end()){
        auto pr = *itR;
        int leftEnd = pr.first, leftStart = pr.second;
        l = leftStart;
        byR.erase(itR);
        byL.erase(l);
    }
    auto itL = byL.find(x+1);
    if(itL != byL.end()){
        auto pr = *itL;
        int rightStart = pr.first, rightEnd = pr.second;
        r = rightEnd;
        byL.erase(itL);
        byR.erase(r);
    }
    byL[l] = r;
    byR[r] = l;
}

int white(int x, map<int,int> &byL, map<int,int> &byR) {
    auto it = byL.upper_bound(x);
    if(it != byL.begin()){
        it--;
        auto pr = *it;
        int l = pr.first, r = pr.second;
        if(x >= l && x <= r){
            return r+1;
        }
    }
    it = byL.lower_bound(x+1);
    if(it == byL.end()) return x+1;
    auto pr = *it;
    int nextL = pr.first, nextR = pr.second;
    if(nextL == x+1) return nextR + 1;
    return x+1;
}

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    set<int> bl;
    for (int i = 0; i < m; ++i) {
        int a; cin >> a;
        bl.insert(a);
    }

    map<int,int> byL;
    map<int,int> byR;

    for(auto x : bl) black(x, byL, byR);

    set<int> ans(bl.begin(), bl.end());

    for(int i=1; i<=n; i++){
        int pos = 1;
        for(int j=0; j<i; j++){
            if(s[j] == 'A'){
                pos++;
            } 
            else{
                pos = white(pos, byL, byR);
            }
        }
        ans.insert(pos);
        black(pos, byL, byR);
    }
    cout << ans.size() << endl;
    out(ans);
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