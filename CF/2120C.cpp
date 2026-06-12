#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vint vector<int>
#define out(v) for(auto &i: v) cout<<i<<" ";cout << endl;

void solve(){
    ll n, m; cin >> n >> m;
    vint arr;
    if(m > n*(n+1)/2 || m<n){
        cout << "-1\n"; return;
    }
    if(m == n){
        cout << "1\n";
        for(int i=1; i<n; i++){
            cout <<i<< " " <<i+1<< endl;
        } 
        return;
    }
    else if(m == n*(n+1)/2){
        cout << n << endl;
        for(int i=n-1; i>=1; i--){
            cout <<i+1<< " " <<i<< endl;
        } 
        return;
    }
    ll red = (n*(n+1)/2) - m, copy = n, rem = 0, idx = -1;
    for(int i=n-1; i>=1; i--){
        if(red >= i){
            red -= i;
            copy--; rem++;
            if(red == 0){
                break;
            }
        }
        else{
            idx = red;
            break;
        }
    }
    if(idx == -1){
        for(int i=copy; i>=1; i--){
            arr.push_back(i);
        }
        for(int i=copy+1; i<=n; i++){
            arr.push_back(i);
        }
    }
    else{
        int j = copy-1;
        for(int i=0; i<idx; i++, j--){
            arr.push_back(j);
        }
        arr.push_back(copy);
        for(int i=j; i>=1; i--){
            arr.push_back(i);
        }
        for(int i=copy+1; i<=n; i++){
            arr.push_back(i);
        }
    }
    cout << arr[0] << endl;
    for(int i=0; i<n-1; i++){
        cout << arr[i] << " " << arr[i+1] << endl;
    }
}

int main() {
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}