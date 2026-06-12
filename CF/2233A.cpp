#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n, x, y, z; cin >> n >> x >> y >> z;
    int ans1 = (n+x+y-1)/(x+y), ans2 = 0;
    if(x*z >= n) ans2 = (n+x-1)/x;
    else ans2 = z + (n-x*z + x+10*y - 1)/(x+10*y);
    cout << min(ans1, ans2) << endl;
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