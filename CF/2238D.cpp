#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

const int MAXN = 1000005;
int spf[MAXN];

void precompute() {
    for (int i = 2; i < MAXN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    int tot = 0, prime = 0;
    while(n>1){
        int p = spf[n];
        prime++;
        while(n%p == 0){
            tot++;
            n/=p;
        }
    }
    cout << tot + prime - 1 << '\n';
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    precompute();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}