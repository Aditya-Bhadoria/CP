#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    vint arr(n), ans;
    for(int i=0; i<n; i++) cin >> arr[i];
    ans.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i] > ans.back()) ans.push_back(arr[i]);
        else{
            auto x = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[x] = arr[i];
        }
    }
    cout << ans.size() << endl;
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