#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    vll arr(n);
    ll one = 0, ans = 0, pos = 0, sum = 0, num = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] == 1) one++;
        else{
            num++;
            ans += arr[i];
            pos += (arr[i]/2 - 1);
        }
        sum += arr[i];
    }
    if(num == 1){ ans++; one--; }
    ans += min(pos, one);
    if(sum < 3) ans = 0;
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