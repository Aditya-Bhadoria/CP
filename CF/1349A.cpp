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

const int MAX = 2e5 + 4;
vector<bool> prime(MAX, true);
void solve(){
    prime[0] = prime[1] = false;
    for(int i=2; i<MAX; i++){
        if(prime[i]){
            for(int j=2*i; j<MAX; j = j+i){
                prime[j] = false;
            }
        }
    }
    int n; cin >> n;
    vll arr(n), pr; in(arr);
    ll maxi = *max_element(all(arr));
    for(int i=2; i<=maxi; i++) if(prime[i]) pr.pb(i);
    int x = pr.size();
    vector<vll> res(x, vll(2, 1e6));
    for(int i=0; i<x; i++){
        for(int j=0; j<n; j++){
            int copy = arr[j], po = 0;
            while(copy%pr[i] == 0){
                copy /= pr[i];
                po++;
            }
            if(po < res[i][0]){
                res[i][1] = res[i][0];
                res[i][0] = po;
            }
            else if(po < res[i][1]) res[i][1] = po;
            if(res[i][0] == 0 && res[i][1] == 0){
                break;
            }
        }
    }
    ll ans = 1;
    for(int i=0; i<x; i++){
        ans *= pow(pr[i], res[i][1]);
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