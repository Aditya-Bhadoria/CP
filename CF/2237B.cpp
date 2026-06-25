#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    vll a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    vll a2 = a;
    sort(a2.begin(), a2.end());
    for(int i=0; i<n; i++){
        if(a2[i] > b[i]){
            cout << "-1\n"; return;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(a[i] > b[i]){
            int j = i+1;
            while(j < n && a[j] > b[i]) j++;
            ans += (j-i);
            ll temp = a[j];
            for(int k=j; k>i; k--) a[k] = a[k-1];
            a[i] = temp;
        }
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