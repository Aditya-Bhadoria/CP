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
    // knapsack ahh

    // micro archi - > haris haris

    int n, x; cin >> n >> x;
    vint h(n), s(n); in(h); in(s);
    vector<vint> dp(n+1, vint(x+1, 0));
    /*
	 * dp[i][j] is the most number of pages that can be bought from
	 * the first i books and by spending at most j amount of money.
	 */
    for(int i=1; i<=n; i++){
        int cost = h[i-1], page = s[i-1];
        for(int j=1; j<=x; j++){
            /*
			 * if the current book is not bought, the the number of pages is
			 * the same as number of pages bought for first i-1 books using
			 * j amount of money
			 */
			dp[i][j] = dp[i-1][j];
			if(cost <= j){
				/*
				 * if the current book can be bought, then store the most
				 * number of pages using the remaining money after buying
				 * the current book plus the pages for the current book.
				 */
				dp[i][j] = max(dp[i][j], dp[i-1][j-cost] + page);
			}
        }
    }
    cout << dp[n][x] << endl;
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