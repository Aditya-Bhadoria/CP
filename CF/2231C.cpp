#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n; cin >> n;
    vll arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<ll, ll> mp;
    ll curr = arr[0], s = 0;
    while(mp.find(curr) == mp.end()){
        mp[curr] = s;
        if(curr%2 == 0) curr /= 2;
        else curr++;
        s++;
    }
    for(int i=1; i<n; i++){
        map<ll, ll> mp2;
        curr = arr[i];
        s = 0;
        while(mp2.find(curr) == mp2.end()){
            mp2[curr] = s;
            if(curr%2 == 0) curr /= 2;
            else curr++;
            s++;
        }
        map<ll, ll> mp3;
        for(auto [val, step] : mp){
            if(mp2.count(val)) mp3[val] = step + mp2[val];
        }
        mp = mp3;
    }
    ll ans = 1e9;
    for(auto [val, step] : mp){
        ans = min(ans, step);
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
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}