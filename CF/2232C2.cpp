#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve() {
    ll n, x, s; cin >> n >> x >> s;
    string u; cin >> u;
    ll emp = x, opn = 0, ae = 0, ans = 0;
    for(int i=0; i<n; i++){
        if(u[i] == 'I' && emp > 0){
            emp--; ans++;
            opn += (s-1);
        }
        else if(u[i] == 'E'){
            if(opn > 0){
                opn--; ans++;
            }
            else if(emp > 0 && ae > 0){
                emp--; ans++; ae--;
                opn += (s-1);
            }
        }
        else if(u[i] == 'A'){
            if(opn > 0){
                opn--; ans++; ae++;
            }
            else if(emp > 0){
                emp--; ans++;
                opn += (s-1);
            }
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