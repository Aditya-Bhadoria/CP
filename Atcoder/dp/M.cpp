#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

void solve(){
    // dp[i][j] -> ways to distribute j candies to first i children
    // so dp[i][j] = dp[i-1][j] + dp[i-1][j-1] ... dp[i-1][j-arr[i]]
    // for dp[i][j+1] = dp[i-1][j+1] + d[i-1][j] ... dp[i-1][j+1-arr[i]]
    // so there is a overlap, we can reuse the sum variable
    // New Sum = Old Sum + Incoming Element - Outgoing Element
    // sum = (sum - dp[i-1][l]); // Ejecting the element that fell out of the window
    // sum = (sum + dp[i-1][r]); // Absorbing the brand new element into the window

    for(int i=1; i<n; i++){
        int l=0, r=0;
        ll sum = 0;
        for(int j=0; j<=k; j++){
            if(r-l > arr[i]){
                sum = (sum-dp[i-1][l]+mod)%mod;
                l++;
            }
            sum = (sum+dp[i-1][r])%mod;
            r++;
            dp[i][j] = sum;
        }
    }
    cout << dp[n-1][k] << endl;
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