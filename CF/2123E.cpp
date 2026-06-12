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
    ll pref = 1;
    while (b) {
        if (b & 1) pref *= a;
        b >>= 1;
        a *= a;
    }
    return pref;
}

ll pow(ll a, ll b, ll c) {
    ll pref = 1;
    while (b) {
        if (b & 1) pref = (pref * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return pref;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vll arr(n); in(arr);
        vll pres(n+1, 0), freq(n+1, 0);
        for(int i=0; i<n; i++){
            if(arr[i] <= n){
                freq[arr[i]]++;
                pres[arr[i]] = 1;
            }
        }
        int mex = 0;
        while(pres[mex]) mex++;
        vll temp(n+2, 0);
        for(int m = 0; m <= mex; m++){
            ll hi = n-m, lo = freq[m];
            if(lo <= hi){
                temp[lo]++; temp[hi+1]--;
            }
        }
        vll ans(n+1, 0);
        ans[0] = temp[0];
        for(int i=1; i<=n; i++) ans[i] = ans[i-1] + temp[i];
        out(ans);
    }
    return 0;
}