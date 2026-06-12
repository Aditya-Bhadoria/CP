#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vll a(n), c(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> c[i];
    vll c2 = c;
    sort(c2.begin(), c2.end());
    if(c2 != c){ cout << "NO\n"; return; }
    if(s[0] == '1' && a[0] != c[0]){ cout << "NO\n"; return; }
    a[0] = c[0];
    ll curr = a[0];
    for(int i=1; i<n; i++){
        if(c[i] > c[i-1]){
            ll x = c[i] - curr;
            if(s[i] == '1' && a[i] != x){ cout << "NO\n"; return; }
            a[i] = x;
            curr = c[i];
        }
        else{
            if(i == n-1){
                if(s[i] == '0') a[i] = 0; 
                else if(curr + a[i] > c[i]) { cout << "NO\n"; return; }
                curr += a[i]; continue;
            }
            if(s[i] == '1'){
                if(curr + a[i] > c[i]){ cout << "NO\n"; return; }
                curr += a[i];
            }
            else if(s[i] == '0' && s[i+1] == '0'){
                a[i] = 0;
                curr += a[i];
            }
            else if(s[i] == '0' && s[i+1] == '1'){
                ll curr2 = 0, max2 = 0, newval = 0;
                bool forced = false;
                for(int k = i+1; k<n; k++){
                    if(s[k] == '0') break;
                    curr2 += a[k];
                    max2 = max(max2, curr2);
                    if(c[k] > c[k-1]){
                        forced = true;
                        newval = c[k]-curr-curr2;
                        break;
                    }
                }
                if(forced) a[i] = newval;
                else a[i] = c[i]-curr-max2;
                curr += a[i];
            }
        }
    }
    cout << "YES\n";
    for(int i=0; i<n; i++) cout << a[i] << " ";
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