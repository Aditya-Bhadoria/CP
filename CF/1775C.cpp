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

ll solve2(ll n, ll x){
    if (n == x) return n;
 
    if ((n & x) != x) return -1;
    
    int msbn=log2(n);
    int lsbx=-1;
    for(int i=0;i<=63;i++){
        if((x & (1ll<<i))){
            lsbx=i;
            break;
        }
    }
    if(lsbx==-1){
        // cout<<"all"<<"\n";
        return (1ll<<(msbn+1));
    }
    for (int i=lsbx;i<=msbn;i++){
        long long bx=x&(1ll<<i),nx=n&(1ll<<i);
        if(bx!=nx){
            return -1;
        }
    }
    long long diff = n - x;
    long long msb_pos = 0;
    while ((1LL << (msb_pos + 1)) <= diff) {
        msb_pos++;
    }
 
    if ((x & (1LL << (msb_pos + 1) ))) {
        return -1;
    }
 
    long long m = x | (1LL << (msb_pos + 1));
 
    return m;
}

void solve() {
    ll n, x; cin >> n >> x;
    cout << solve2(n, x) << endl;
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