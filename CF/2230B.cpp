#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    string s1; cin >> s1;
    int n = s1.size();
    string s;
    for(int i=0; i<n; i++) if(s1[i] != '4') s.push_back(s1[i]);

    n = s.size();
    vint prefe(n+1, 0), sufo(n+1, 0);  
    for(int i=0; i<n; i++){
        int x = s[i]-'0';
        prefe[i+1] = prefe[i] + (x%2 == 0 ? 1 : 0);
    }
    for(int i=n-1; i>=0; i--){
        int x = s[i]-'0';
        sufo[i] = sufo[i+1] + (x%2 == 1 ? 1 : 0);
    }
    int temp = 0;
    for(int i=0; i<=n; i++){
        temp = max(temp, prefe[i]+sufo[i]);
    }
    cout << s1.length() - temp << endl;
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