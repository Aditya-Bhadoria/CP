#include <bits/stdc++.h>
using namespace std;
bool isPossible(int stall[], int n, int k, int mid){
    int cowCount = 1;
    int lastPos = stall[0];
    for(int i=0; i<n ; i++){
        if(stall[i] - lastPos >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPos = stall[i];
        }
    }
    return false;
}

void solve(){
    /* n = stalls, k = cows, largest min dis such that cows do no fight */
    int s = 0;
    int n, k; cin >> n >> k; 
    int stall[n];
    
    for(int i=0; i<n; i++){ cin >> stall[i]; }
    
    sort(stall, stall + n);
    int e = stall[n-1];
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(stall,n,k,mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    cout << ans << endl;
}

const int N = 1e5 + 20;
int c, n, x[N], dp[N];

void solve2(){
    cin >> n >> c;
    for(int i=0; i<n; i++) cin >> x[i];
    sort(x, x+n);
    int low = 0, high = 1e9 + 20;
    while(high - low > 1){
        int mid = (low + high)/2;
        int ptr = -1;
        for(int i=0; i<n; i++){
            dp[i] = 1;
            while(x[i] - x[ptr + 1] >= mid) ptr++;

            if(ptr != -1) dp[i] = dp[ptr] + 1;
            if(i) dp[i] = max(dp[i], dp[i-1]);
        }
        if(dp[n-1] >= c) low = mid;
        else high = mid;
    }
    cout << low << endl;
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
        // solve -> kind of optimised dp?
        // solve2 -> dp
        
        // solve();
        solve2();
    }
    return 0;
}