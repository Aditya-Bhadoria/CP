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
    string s; cin >> s;
    vint arr;
    for(int i=0; i<n; i++){
        if(s[i] == '1') arr.push_back(i+1);
    }
    if(arr.empty()){
        cout << "YES\n";
        for(int i=n; i>=1; i--) cout << i << " ";
        cout << endl; return;
    }
    bool check = true;
    int x = arr.size();
    if(arr[0] == 2) check = false;
    if(arr[x-1] == n-1) check = false;
    for(int i=0; i<x-1; i++){
        if(arr[i+1] - arr[i] == 2){
            check = false;
            break;
        }
    }
    if(!check){
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    vint p(n, 0);
    for(int i=0; i<x; i++){
        p[arr[i]-1] = arr[i];
    }
    int first = arr[0];
    if(first > 1){
        int maxi = first-1;
        for(int i=1; i<first; i++){
            p[i-1] = maxi - i + 1;
        }
    }
    for(int i=0; i< x-1; i++){
        int l = arr[i]+1, r = arr[i+1]-1;
        if(l <= r){
            int maxi = arr[i+1]-1;
            for(int j=l; j<=r; j++){
                p[j-1] = maxi - j + l;
            }
        }
    }
    int last = arr[x-1];
    if(last < n){
        int l = last+1, maxi = n;
        for(int j=l; j <= n; j++){
            p[j-1] = maxi - j + l;
        }
    }
    out(p);
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