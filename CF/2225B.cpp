#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    string s; cin >> s;
    int n = s.size(), cnt = 0;
    for(int i=0; i<n-1; i++) if(s[i] == s[i+1]) cnt++;
    if(cnt > 2) cout << "NO\n"; 
    else cout << "YES\n";
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