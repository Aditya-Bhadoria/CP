#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n; cin >> n;
    vll arr(n);
    ll maxi = 0, k = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
        k = max(k, maxi-arr[i]);
    }
    ll temp = 0, check = 1;
    for(int i=0; i<n; i++){
        if(arr[i] >= temp) temp = arr[i];
        else{
            if(arr[i]+k < temp){
                check = 0;
                break;
            }
            temp = arr[i]+k;
        }
    }
    if(check) cout << "YES\n";
    else cout << "NO\n";
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