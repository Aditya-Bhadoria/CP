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
        vector<vll> gr(n+1);
        vll deg(n+1,0);
        int v1, v2, check = 0;
        for(int i=0 ; i<n-1 ; i++){
            cin >> v1 >> v2;
            deg[v1]++;
            deg[v2]++;
            gr[v1].pb(v2);
            gr[v2].pb(v1);
        }
        for(int i=1; i<=n ; i++){
            if(deg[i]==2) check=i;
        }
        if(check == 0){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<pair<ll,ll>> ans;
        vll vis(n+1,0);
        vis[f]=1;
        ans.push_back({f,gr[f][0]});
        queue<ll> q;
        q.push(gr[f][0]);
        vis[gr[f][0]]=1;
        while(!q.empty()){
            int ver=q.front();
            q.pop();
            for(auto it:gr[ver]){
                if(vis[it]) continue;
                vis[it]=1;
                ans.push_back({it,ver});
                for(auto i:gr[it]){
                    if(vis[i]) continue;
                    ans.push_back({it,i});
                    q.push(i);
                    vis[i]=1;
                }
            }
        }

        ans.push_back({gr[f][1],f});
        q.push(gr[f][1]);
        vis[gr[f][1]]=1;
        while(!q.empty()){
            int ver=q.front();
            q.pop();
            for(auto it:gr[ver]){
                if(vis[it]) continue;
                vis[it]=1;
                ans.push_back({ver,it});
                for(auto i:gr[it]){
                    if(vis[i]) continue;
                    ans.push_back({i,it});
                    q.push(i);
                    vis[i]=1;
                }
            }
        }

        for(auto [x,y]:ans){
            cout<<x<<" "<<y<<endl;
        }

    }
    return 0;
}