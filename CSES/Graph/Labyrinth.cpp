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
int n, m, srcx = -1, srcy = -1, destx = -1, desty = -1;
bool isValid(int row, int col, vector<vint> &grid, vector<vint> &visited){
    return row >= 0 && row < n && col >= 0 && col < m &&
           grid[row][col] && !visited[row][col];
}
bool isValid2(int row, int col){
    return row >=0 && row < n && col >=0 && col < m;
}
void backtrack(int i, int j, string &ans, vector<vint>&dist){
    if(i == srcx && j == srcy) return;
    int x = dist[i][j];
    if(isValid2(i, j+1) && dist[i][j+1] == x-1){
        ans.push_back('L');
        backtrack(i, j+1, ans, dist);
    }
    else if(isValid2(i+1, j) && dist[i+1][j] == x-1){
        ans.push_back('U');
        backtrack(i+1, j, ans, dist);
    }
    else if(isValid2(i-1, j) && dist[i-1][j] == x-1){
        ans.push_back('D');
        backtrack(i-1, j, ans, dist);
    }
    else if(isValid2(i, j-1) && dist[i][j-1] == x-1){
        ans.push_back('R');
        backtrack(i, j-1, ans, dist);
    }
}
void solve(){
    cin >> n >> m;
    vector<vint> grid(n, vint(m, 0));
    vector<vint> vis(n, vint(m, 0)), dist(n, vint(m, 1e9));
    string ans;
    queue<vint> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch; cin >> ch;
            if(ch == '#') vis[i][j] = 1;
            else grid[i][j] = 1;
            if(ch == 'A'){ srcx = i; srcy = j; }
            if(ch == 'B'){ destx = i; desty = j; }
        }
    }
    vint dRow = {-1, 1, 0, 0};
    vint dCol = {0, 0, -1, 1};
    dist[srcx][srcy] = 0;
    vis[srcx][srcy] = 1;
    q.push({srcx, srcy, 0});
    while(!q.empty()){
        vint curr = q.front();
        q.pop();
        int row = curr[0], col = curr[1], dis = curr[2];
        for(int i=0; i<4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if(isValid(nRow, nCol, grid, vis)){
                dist[nRow][nCol] = dis + 1;
                vis[nRow][nCol] = 1;
                q.push({nRow, nCol, dis+1});
            }
        }
    }
    if(dist[destx][desty] == 1e9){ cout << "NO\n"; return; }
    // for(int i=0; i<n; i++){
    //     // for(int j=0; j<m; j++){
    //         // if(dist[i][j] == 1e9) cout << "I ";
    //         // else cout << dist[i][j] << " ";
    //     // } cout << endl;
    // }
    backtrack(destx, desty, ans, dist);
    reverse(all(ans));
    cout << "YES\n" << ans.size() << endl << ans;
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
    while(t--){
        solve();
    }
    return 0;
}