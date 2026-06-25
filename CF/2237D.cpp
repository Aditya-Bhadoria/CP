#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    vll pref(3, 0);
    pref[0] = 1;
    ll curr = 0, ans = n*(n+1)/2, len = 1;
    for(int i=0; i<n; i++){
        curr = (curr + (s[i] == '0' ? 1 : 2)) % 3;
        ans -= pref[curr];
        pref[curr]++;
    }
    for(int i=1; i<n; i++){
        if(s[i] != s[i-1]) len++;
        else{
            ans -= (len-1)*(len-1)/4;
            len = 1;
        }
    }
    ans -= (len-1)*(len-1)/4;
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