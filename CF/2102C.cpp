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
void solve(){
    int n; cin >> n;
    if(n == 1){ cout << "0\n"; return; }
    if(n == 2){ cout << "0 1\n3 2\n"; return; }
    vector<vll> grid(n, vll(n, 0));
    int x = (n-1)/2, y = (n-1)/2;
    int direc[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
    if(n%2 == 0){
        direc[1][0] = 1; direc[1][1] = 0;
        direc[3][0] = -1; direc[3][1] = 0;
    }
    int dir = 0, step = 1, cnt = 0, num = 1;
    grid[x][y] = 0;
    while(num < n*n){
        for(int i=0; i<step; i++){
            x += direc[dir][0];
            y += direc[dir][1];
            if(x >= 0 && x<n && y>=0 && y<n){
                grid[x][y] = num++;
            } 
            else{
                x -= direc[dir][0];
                y -= direc[dir][1];
                break;
            }
        }
        cnt++; dir++; dir %= 4;
        if(cnt%2 == 0){
            step++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        } cout << endl;
    }
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