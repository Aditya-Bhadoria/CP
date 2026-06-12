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
    vector<vint> outg(n, vint(n,0)), inc(n, vint(n,0));
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<n; j++){
            if(s[j] == '1'){
                outg[i][j] = 1;
                inc[j][i] = 1;
            }
        }
    }
    vector<pair<int,int>> edges;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j && outg[i][j]){
                int cnt = 0;
                for(int k=0; k<n; k++){
                    if(outg[i][k] && inc[j][k]) cnt++;
                }
                if(cnt == 2) edges.push_back({i,j});
            }
        }
    }
    if(edges.size() != n-1){
        cout << "NO\n"; return;
    }
    vector<vint> adj1(n), adj2(n);
    for(auto it : edges){
        int u = it.first, v = it.second;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
        adj2[u].push_back(v);
    }
    vint vis(n,0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    int cnt = 1;
    while(!q.empty()){
        int node = q.front(); 
        q.pop();
        for(auto it : adj1[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
                cnt++;
            }
        }
    }
    if(cnt != n){
        cout << "NO\n"; return;
    }
    for(int i=0; i<n; i++){
        vint vis1(n,0);
        queue<int> q1;
        q1.push(i);
        vis1[i] = 1;

        while(!q1.empty()){
            int node = q1.front();
            q1.pop();
            for(auto it : adj2[node]){
                if(!vis1[it]){
                    vis1[it] = 1;
                    q1.push(it);
                }
            }
        }
        for(int j=0; j<n; j++){
            if(vis1[j] != outg[i][j]){
                cout << "NO\n"; return;
            }
        }
    }
    cout << "YES\n";
    for(auto it : edges){
        cout << it.first+1 << " " << it.second+1 << "\n";
    }
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