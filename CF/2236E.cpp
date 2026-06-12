#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

vector<vint> minr;
vector<vint> maxl;
void solve() {
    int n; cin >> n;
    vint arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    minr.assign(n+1, vint(n+1, 1e9));
    maxl.assign(n+1, vint(n+1, -1e9));
    vint last(n+1, -1);
    for(int l=0; l<n; l++){
        int mini = arr[l], maxi = arr[l];
        for(int r=l; r<n; r++){
            if(last[arr[r]] == l) break;
            last[arr[r]] = l;
            mini = min(mini, arr[r]);
            maxi = max(maxi, arr[r]);
            if(maxi - mini == r-l){
                minr[mini][maxi] = min(minr[mini][maxi], r);
                maxl[mini][maxi] = max(maxl[mini][maxi], l);
            }
        }
    }
    for(int l=n/2; l>=1; l--){
        for(int v=1; v + 2*l - 1 <= n; v++){
            if(minr[v][v+l-1] < maxl[v+l][v+2*l-1] || minr[v+l][v+2*l-1] < maxl[v][v+l-1]){
                cout << l << endl;
                return;
            }
        }
    }
    cout << "0\n";
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