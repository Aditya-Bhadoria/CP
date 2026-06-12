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
    vll a(n), b(n); in(a); in(b);
    vll c(n, 0);
    ll ans = 0, gc1 = gcd(a[0], a[1]), gc2 = 0;
    if(a[0] != gc1){
        if(b[0] >= gc1){ 
            // ans++; 
            a[0] = gc1; c[0] = 1; 
        }
    }
    else{
        ll temp = a[0];
        for(ll i=2; ; i++){
            temp += a[0];
            if(temp > b[0]) break;
            else if(gcd(temp, a[1]) == gc1){
                // ans++; 
                a[0] = temp; c[0] = 1;
                break;
            }
        }
    }
    gc1 = gcd(a[n-2], a[n-1]);
    if(a[n-1] != gc1){
        if(b[n-1] >= gc1){ 
            // ans++; 
            a[n-1] = gc1; c[n-1] = 1; 
        }
    }
    else{
        ll temp = a[n-1];
        for(ll i=2; ; i++){
            temp += a[n-1];
            if(temp > b[n-1]) break;
            else if(gcd(temp, a[n-2]) == gc1){
                // ans++; 
                a[n-1] = temp; c[n-1] = 1;
                break;
            }
        }
    }
    for(ll i=1; i<n-1; i++){
        gc1 = gcd(a[i-1], a[i]);
        gc2 = gcd(a[i], a[i+1]);
        ll lc = lcm(gc1, gc2);
        if(a[i] != lc){
            if(b[i] >= lc){
                ans++; 
                a[i] = lc; c[i] = 1;
            }
        }
        else{
            ll temp = a[i];
            for(ll j=2; ; j++){
                temp += a[i];
                if(temp > b[i]) break;
                else if((gcd(temp, a[i-1]) == gc1) && (gcd(temp, a[i+1]) == gc2)){
                    ans++; 
                    a[i] = temp; c[i] = 1;
                    break;
                }
            }
        }
    }
    if(!c[0]){
        gc1 = gcd(a[0], a[1]);
        if(a[0] != gc1){
            if(b[0] >= gc1){ 
                // ans++; 
                a[0] = gc1; c[0] = 1; 
            }
        }
        else{
            ll temp = a[0];
            for(ll i=2; ; i++){
                temp += a[0];
                if(temp > b[0]) break;
                else if(gcd(temp, a[1]) == gc1){
                    // ans++; 
                    a[0] = temp; c[0] = 1;
                    break;
                }
            }
        }
    }
    if(!c[n-1]){
        gc1 = gcd(a[n-2], a[n-1]);
        if(a[n-1] != gc1){
            if(b[n-1] >= gc1){ 
                // ans++; 
                a[n-1] = gc1; c[n-1] = 1; 
            }
        }
        else{
            ll temp = a[n-1];
            for(ll i=2; ; i++){
                temp += a[n-1];
                if(temp > b[n-1]) break;
                else if(gcd(temp, a[n-2]) == gc1){
                    // ans++; 
                    a[n-1] = temp; c[n-1] = 1;
                    break;
                }
            }
        }
    }
    ans += c[0]+c[n-1];
    // out(a);
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