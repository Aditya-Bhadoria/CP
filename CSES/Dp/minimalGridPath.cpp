#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    int n; cin >> n;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];
    vector<vector<bool>> active(n, vector<bool>(n, false));
    active[0][0] = true;
    string ans = "";
    ans += grid[0][0];
    for(int k=1; k <= 2*n-2; k++){
        char min_char = 'Z' + 1;
        for(int i=0; i<n; i++){
            int j = k - i;
            if (j < 0 || j >= n) continue;
            bool can_reach = false;
            if (i > 0 && active[i - 1][j]) can_reach = true;
            if (j > 0 && active[i][j - 1]) can_reach = true;
            if (can_reach) min_char = min(min_char, grid[i][j]);
        }
        ans += min_char;
        for (int i = 0; i < n; i++) {
            int j = k - i;
            if (j < 0 || j >= n) continue;
            bool can_reach = false;
            if (i > 0 && active[i - 1][j]) can_reach = true;
            if (j > 0 && active[i][j - 1]) can_reach = true;
            if (can_reach && grid[i][j] == min_char) active[i][j] = true;
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}