#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    vll arr(n); 
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            swap(arr[i], arr[i-1]);
            arr[i] += arr[i-1];
        }
    }
    cout << arr[n-1] << endl;
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