#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    vint arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    int ans = n;
    for(int i=0; i<n; i++){
        int l = 0, r = 0;
        for(int j=0; j<n; j++){
            if(arr[j] < arr[i]) l++;
            else if(arr[j] > arr[i]) r++;
        }
        ans = min(ans, max(l,r));
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