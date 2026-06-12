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
    vector<vint> v(n, vint(n, 0));
    int c = 0;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<n; j++){
            if(s[j] == '#'){
                c++;
                v[i][j] = 1;
            }
        }
    }
    if(c <= 1){
        cout << "YES\n"; return;
    }
    else if(c == 4){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int tot=1;
                if(v[i][j] == 1){
                    if(j < n-1) tot += v[i][j+1];
                    if(i < n-1) tot += v[i+1][j];
                    if(i<n-1 && j<n-1) tot += v[i+1][j+1];
                }
                if(tot == 4){
                    cout << "YES\n"; return;
                }
            }
        }
    }
    int sx = -1, sy = -1;
    for(int i=0; i<n && sx == -1; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]){ 
                sx = i; sy = j; 
                break; 
            }
        }
    }
    if(sx != -1){
        {
            vector<vint> seen(n, vint(n,0));
            int x = sx, y = sy, idx = 0, cnt = 0;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                if (v[x][y] && !seen[x][y]) { cnt++; seen[x][y] = 1; }
                if ((idx & 1) == 0) x += 1; else y += 1; 
                idx++;
            }
            if(cnt == c){ 
                cout << "YES\n"; 
                return; 
            }
        }
        {
            vector<vint> seen(n, vint(n,0));
            int x = sx, y = sy, idx = 0, cnt = 0;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                if (v[x][y] && !seen[x][y]) { ++cnt; seen[x][y] = 1; }
                if ((idx & 1) == 0) y += 1; else x += 1; 
                ++idx;
            }
            if (cnt == c) { cout << "YES\n"; return; }
        }

        {
            vector<vint> seen(n, vint(n,0));
            int x = sx, y = sy, idx = 0, cnt = 0;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                if (v[x][y] && !seen[x][y]) { ++cnt; seen[x][y] = 1; }
                if ((idx & 1) == 0) y -= 1; else x += 1; 
                ++idx;
            }
            if (cnt == c) { cout << "YES\n"; return; }
        }

        {
            vector<vint> seen(n, vint(n,0));
            int x = sx, y = sy, idx = 0, cnt = 0;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                if (v[x][y] && !seen[x][y]) { ++cnt; seen[x][y] = 1; }
                if ((idx & 1) == 0) x += 1; else y -= 1; 
                ++idx;
            }
            if (cnt == c) { cout << "YES\n"; return; }
        }
    }

    sx = -1; sy = -1;
    for (int i = n - 1; i >= 0 && sx == -1; --i) {
        for (int j = 0; j < n; ++j) {
            if (v[i][j]) { sx = i; sy = j; break; }
        }
    }

    if (sx != -1) {
        {
            vector<vint> seen(n, vint(n,0));
            int x = sx, y = sy, idx = 0, cnt = 0;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                if (v[x][y] && !seen[x][y]) { ++cnt; seen[x][y] = 1; }
                if ((idx & 1) == 0) x -= 1; else y += 1; 
                ++idx;
            }
            if (cnt == c) { cout << "YES\n"; return; }
        }

        {
            vector<vint> seen(n, vint(n,0));
            int x = sx, y = sy, idx = 0, cnt = 0;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                if (v[x][y] && !seen[x][y]) { ++cnt; seen[x][y] = 1; }
                if ((idx & 1) == 0) y += 1; else x -= 1; 
                ++idx;
            }
            if (cnt == c) { cout << "YES\n"; return; }
        }

        {
            vector<vint> seen(n, vint(n,0));
            int x = sx, y = sy, idx = 0, cnt = 0;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                if (v[x][y] && !seen[x][y]) { ++cnt; seen[x][y] = 1; }
                if ((idx & 1) == 0) y -= 1; else x -= 1; 
                ++idx;
            }
            if (cnt == c) { cout << "YES\n"; return; }
        }

        {
            vector<vint> seen(n, vint(n,0));
            int x = sx, y = sy, idx = 0, cnt = 0;
            while (x >= 0 && x < n && y >= 0 && y < n) {
                if (v[x][y] && !seen[x][y]) { ++cnt; seen[x][y] = 1; }
                if ((idx & 1) == 0) x -= 1; else y -= 1; 
                ++idx;
            }
            if (cnt == c) { cout << "YES\n"; return; }
        }
    }
    cout << "NO\n";
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