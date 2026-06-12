#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n; cin >> n;
    for(int i=1; i<=n; i++) cout << i << " ";
    for(int i=1; i<=n; i++) cout << i << " ";
    for(int i=2; i<=n; i++) cout << i << " ";
    cout << 1 << " ";
    for(int i=1; i<=n; i++) cout << i << " ";
    cout << endl;
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