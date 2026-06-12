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

vector<vint> dp(505, vint(505, -1));
int memo(int a, int b){
    if(a == b) return dp[a][b] = 0;
    if(dp[a][b] != -1) return dp[a][b];
    if(dp[b][a] != -1) return dp[b][a];
    int ans = 1e9;
    for(int i=1; i<=b/2; i++){
        ans = min(ans, 1 + memo(a, i) + memo(a, b-i));
    }
    for(int i=1; i<=a/2; i++){
        ans = min(ans, 1 + memo(i, b) + memo(a-i, b));
    }
    dp[a][b] = ans;
    dp[b][a] = ans;
    return ans;
}

int table(int w, int h){
    vector<vector<int>> dp2(w+1,vector<int>(h+1));
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            if (i == j) {
                dp2[i][j] = 0;
            } else {
                dp2[i][j] = 1e9;
                for (int k = 1; k < i; k++) {
                    dp2[i][j] = min(dp2[i][j], dp2[k][j]+dp2[i-k][j]+1);
                }
                for (int k = 1; k < j; k++) {
                    dp2[i][j] = min(dp2[i][j], dp2[i][k]+dp2[i][j-k]+1);
                }
            }
        }
    }
    return dp2[w][h];
}

void solve() {
    int a, b; cin >> a >> b;
    // cout << memo(a, b) << endl;
    cout << table(a, b) << endl;
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