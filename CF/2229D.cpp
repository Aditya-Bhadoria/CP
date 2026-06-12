#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

bool isPos(int mid, int n, vint a, vint b){
    vint v;
    for(int i=0; i<n; i++){
        int c = 0;
        if(a[i] >= mid) c++;
        if(b[i] >= mid) c++;
        if(c != 1) v.push_back(c);
    }
    if(v.empty()) return false;
    int pos = 0, neg = 0;
    bool prev = false;
    for(int x : v){
        if(x){
            pos++;
            prev = false;
        }
        else if(!prev){
            neg++;
            prev = true;
        }
    }
    return pos > neg;
}

void solve() {
    int n; cin >> n;
    vint a(n), b(n);
    int maxi = 0, ans = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        maxi = max(maxi, b[i]);
    }
    int lo = 1, hi = maxi, mid = lo + (hi-lo)/2;
    while(hi>=lo){
        mid = lo + (hi-lo)/2;
        if(isPos(mid, n, a, b)){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
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