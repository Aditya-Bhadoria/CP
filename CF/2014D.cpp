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
    int n, d, k; cin >> n >> d >> k;
    vector<pii> arr(k);
    for(int i=0; i<k; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    vint pref(n+1, 0);
    for(auto &it : arr){
        int l = it.first, r = it.second;
        pref[l]++;
        if(r+1 <= n) pref[r+1]--;
    }
    for(int i=2; i<=n; i++){
        pref[i] += pref[i-1];
    }
    vint pref2(n+1, 0);
    for(auto &it : arr){
        int l = it.first, r = it.second;
        int mini = max(1, l-d+1);
        int maxi = min(n-d+1, r);
        if(mini <= maxi){
            pref2[mini]++;
            if(maxi+1 <= n){
                pref2[maxi+1]--;
            }
        }
    }
    for(int i=2; i+d-1<=n; i++){
        pref2[i] += pref2[i-1];
    }
    int maxi = -1, ans1 = -1;
    int mini = n+1, ans2 = -1;
    for(int i = 1; i<= n-d+1; i++){
        if(pref2[i] > maxi){
            maxi = pref2[i];
            ans1 = i;
        }
        if(pref2[i] < mini){
            mini = pref2[i];
            ans2 = i;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
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
        solve();
    }
    return 0;
}