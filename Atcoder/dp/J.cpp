#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    dp[x][y][z] = 1 + dp[x][y][z] * (N-(x+y+z))/N // plate with 0 sushi
                    + dp[x-1][y][z] * x/N // plate with 1 sushi
                    + dp[x][y-1][z] * y/N // 2 sushi
                    + dp[x][y][z-1] * z/N // 3 sushi
    // simplify to :-
    dp[x][y][z] = (N + x*dp[x-1][y][z] + y*dp[x][y-1][z] + z*dp[x][y][z-1]);
    dp[x][y][z] /= (x+y+z);
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