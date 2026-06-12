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
#define pb push_back
#define out(v) for(auto i: v) cout<<i<<" ";

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
        vint a(n);
        for (int i = 0; i<n; i++){
            cin >> a[i];
        }
        int g = a[0];
        for (int i = 1; i < n; i++){
            g = gcd(g, a[i]);
        }
        int cnt = 0;
        for (int i = 0; i<n; i++){
            if(a[i] == g){
                cnt++;
            }
        }
        if(cnt > 0) {
            cout << n - cnt << '\n';
            continue;
        }
        vint b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] / g;
        }
        int maxi = *max_element(b.begin(), b.end());
        vint dist(maxi+1, -1);
        vector<bool> appear(maxi+1, false);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (b[i] <= maxi) {
                if (!appear[b[i]]) {
                    appear[b[i]] = true;
                    dist[b[i]] = 1;
                    q.push(b[i]);
                }
            }
        }
        int min_k = -1;
        while (!q.empty() && min_k == -1) {
            int d = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                int nd = gcd(d, b[i]);
                if (nd > maxi) continue;
                if (dist[nd] == -1) {
                    dist[nd] = dist[d] + 1;
                    if (nd == 1) {
                        min_k = dist[nd];
                        while (!q.empty()) q.pop();
                        break;
                    }
                    q.push(nd);
                }
            }
        }
        if (min_k == -1) {
            min_k = n;
        }
        cout << n + min_k - 2 << '\n';
    }
    return 0;
}