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

string a, b;
string char_list;
bool mark[26];
ll ans, k;
 
ll count_matching_pair(){
    ll tot_pair = 0, match_count = 0;

    for(ll i = 0; i < a.size(); i++) {
        if(a[i] == b[i] || mark[ a[i]-'a' ])
            match_count++;
        else {
            tot_pair += match_count*(match_count+1)/2;
            match_count = 0;
        }
    }
    tot_pair += match_count*(match_count+1)/2;
 
    return tot_pair;
}
 
void solve2(ll pos, ll cnt){
    if(cnt > k) return;
 
    if(pos == char_list.size()) {
        if(cnt == k) ans = max(ans, count_matching_pair());
        return;
    }
 
    solve2(pos+1, cnt);
 
    mark[ char_list[pos]-'a' ] = 1;
    solve2(pos+1, cnt+1);
    mark[ char_list[pos]-'a' ] = 0;
}

void solve() {
    ll n; cin >> n >> k;
    cin >> a >> b;

    unordered_set <char> unq;
    for(auto &ch : a) unq.insert(ch);

    char_list.clear();
    for(auto &x : unq) char_list.pb(x);

    k = min(k, (ll)unq.size());
    memset(mark, 0, sizeof mark);
    ans = 0;
    solve2(0, 0);

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