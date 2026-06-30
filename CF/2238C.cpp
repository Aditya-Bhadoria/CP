#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    vint par(n+1);
    for(int i=2; i<=n; i++) cin >> par[i];
    vint h(n+1, 0), h2(n+1, 0);
    int ans = n;
    for(int i=n; i>=2; i--){
        int ht = h[i]+1;
        if(ht > h[par[i]]){
            h2[par[i]] = h[par[i]];
            h[par[i]] = ht;
        } 
        else if(ht > h2[par[i]]) h2[par[i]] = ht;
    }
    for(int i=1; i<=n; i++) ans += h2[i];
    cout << ans << '\n';
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}