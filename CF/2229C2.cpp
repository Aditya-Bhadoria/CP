#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    int n; cin >> n;
    vll arr(n+1), s(n+1, 1);
    ll sum = 0, mx = 0, opt = 0, cur = 0;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        if(arr[i] < 0) s[i] = -1;
        sum += arr[i];
        mx += arr[i];
    }
    vll suf(n+2, 0);
    for(int i=n; i>=1; i--) suf[i] = suf[i+1] + arr[i];

    for(int i=1; i<=n; i++){
        if(arr[i] > 0){
            ll temp = cur-arr[i]+suf[i+1];
            if(temp > mx){
                mx = temp;
                opt = i;
            }
        }
        cur += abs(arr[i]);
    }
    if(opt == 0){ cout << "0\n\n"; return; }
    vll sp(n+1), temp, ans, ones;
    for(int i=1; i<=n; i++){
        if(i < opt) sp[i] = 1;
        else if(i > opt) sp[i] = s[i];
        else sp[i] = -1;
    }
    for(int i=1; i<=opt; i++){
        int c1 = s[i] * (i+1 <= n ? s[i+1] : 1);
        int c2 = sp[i] * (i+1 <= n ? sp[i+1] : 1);
        if(c1 != c2) temp.push_back(i);
    }
    for(int i=0; i<temp.size(); i++){
        if(s[temp[i]] == -1) ones.push_back(temp[i]);
        else{
            ans.push_back(temp[i]);
            for(auto y : ones) ans.push_back(y);
            ones.clear();
        }
    }
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}