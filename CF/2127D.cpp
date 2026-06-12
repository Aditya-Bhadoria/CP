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

vll fac(2e5 + 1);
bool bfs(int start, int par, vll g[], ll &ans, vint &arranged) {
    stack<pair<int,int>> st;
    st.push({start, par});
    
    while(!st.empty()) {
        auto [ver, parent] = st.top();
        st.pop();
        if(arranged[ver]) continue;
        arranged[ver] = 1;
        int cnt = 0, cnt2 = 0, check = 1;
        for(auto it : g[ver]) {
            if(it == parent) continue;
            if(g[it].size() >= 2) {
                cnt++;
                if(arranged[it]) {
                    check = 0;
                }
            }
            else cnt2++;
            if(cnt > 2) return true;
            st.push({it, ver});
        }
        ans = (ans * fac[cnt2]) % mod;
        if(cnt && check) ans = (ans * 2LL) % mod;
    }
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vll g[n+1];
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vint color(n+1, -1);
    queue<int> q;
    q.push(1);
    color[1] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : g[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                cout << "0\n"; return;
            }
        }
    }
    ll ans = 2;
    vint arranged(n+1, 0);
    if(bfs(1, 0, g, ans, arranged)){
        cout << "0\n"; 
    }
    else{
        cout << ans << endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    fac[0] = 1; // 0! = 1
    for(int i=1; i <= 2e5; i++){
        fac[i] = (fac[i-1] * i) % mod;
    }
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}