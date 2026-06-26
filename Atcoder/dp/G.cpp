#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    // while(!q.empty()){
    //     int par = q.front();
    //     q.pop();
    //     for(auto it : g[par]){
    //         indeg[it]--;
    //         if(indeg[it] == 0) q.push(it);
    //         if(dist[par] + 1 > dist[it]){
    //             dist[it] = dist[par] + 1;
    //         }
    //     }
    // }
    // ans -> max(dist[i])
}

int main(){
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