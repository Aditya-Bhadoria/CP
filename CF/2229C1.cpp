#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    vint arr(n); 
    for(int i=0; i<n; i++) cin >> arr[i];
    int p = 1;
    vint ans;
    for(int i=n-1; i>=0; i--){
        if(p && arr[i] > 0){
            ans.push_back(i);
            p = 0;
        }
        else if(!p && arr[i] < 0){
            ans.push_back(i);
            p = 1;
        }
    }
    cout << ans.size() << endl;
    for(auto it : ans) cout << it+1 << " ";
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