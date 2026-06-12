#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    ll n, m; cin >> n >> m;
    vll arr(n), freq(m, 0);
    ll check = 0, ans = 1;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        freq[arr[i]%m]++;
        if(freq[arr[i]%m] == 2) check = 1;
    }
    if(check){ cout << "0\n"; return; }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans = ans*(abs(arr[j]-arr[i])) % m;
        }
    }
    cout << ans << endl;
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