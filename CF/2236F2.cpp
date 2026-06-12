#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

const int MOD = 1e9 + 7;
const int MAXVAL = 500005;
const int MAXN = 100005;

int spf[MAXVAL];

vint C_arr[MAXVAL];
int req_v_arr[MAXVAL];
vint primes;

vector<vint> pref;
vector<vint> suff;
vint temp_res(20, 0);

void mult_1(const vint& a, int l, int v, vint& res){
    ll curr = 0;
    for(int i=0; i<=v; i++){
        curr += a[i];
        if(i-l-1 >= 0) curr -= a[i-l-1];
        curr %= MOD;
        if(curr < 0) curr += MOD;
        res[i] = curr;
    }
}

void mult(const vint& a, const vint& b, int v, vint& res) {
    fill(res.begin(), res.begin() + v + 1, 0);
    for(int i = 0; i <= v; i++){
        if(!a[i]) continue;
        for(int j=0; j<=v-i; j++){
            res[i+j] = (res[i+j] + 1LL * a[i] * b[j]) % MOD;
        }
    }
}

void precomp(){
    for(int i=2; i < MAXVAL; i++) spf[i] = i;
    for(int i=2; i*i < MAXVAL; i++){
        if(spf[i] == i){
            for(int j = i*i; j<MAXVAL; j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    pref.assign(MAXN, vint(20, 0));
    suff.assign(MAXN, vint(20, 0));
}

void solve() {
    int n, x; cin >> n >> x;
    vint a(n); for(int i=0; i<n; i++) cin >> a[i];
    int temp_x = x;
    while(temp_x > 1){
        int p = spf[temp_x];
        int cnt = 0;
        while(temp_x%p == 0){
            cnt++;
            temp_x /= p;
        }
        req_v_arr[p] = cnt;
        primes.push_back(p);
    }
    for(int i=0; i<n; i++){
        int temp = a[i];
        while(temp > 1){
            int p = spf[temp];
            int cnt = 0;
            while(temp % p == 0) {
                cnt++;
                temp /= p;
            }
            if(C_arr[p].empty() && req_v_arr[p] == 0) {
                primes.push_back(p);
            }
            C_arr[p].push_back(cnt);
        }
    }
    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());
    ll ans = 1;
    for(int p : primes){
        int v = req_v_arr[p];
        vint& C = C_arr[p];
        if(!v){ 
            ll ways_q = 1;
            for(int c : C) ways_q = (ways_q + c) % MOD;
            ans = (ans * ways_q) % MOD;
        } 
        else{
            if(C.empty()){
                ans = 0; break;
            }
            ll ways_q = 0;
            int k = C.size(), max_c = 0;
            for(int c : C) max_c = max(max_c, c);

            for (int mx = 1; mx <= max_c; mx++) {
                pref[0][0] = 1;
                for(int j=1; j<=v; j++) pref[0][j] = 0;
                for(int i=0; i<k; i++){
                    int limit = min({C[i], mx-1, v});
                    mult_1(pref[i], limit, v, pref[i+1]);
                }
                suff[k][0] = 1;
                for(int j=1; j<=v; j++) suff[k][j] = 0;
                for(int i=k-1; i>=0; i--){
                    int limit = min({C[i], mx, v});
                    mult_1(suff[i+1], limit, v, suff[i]);
                }
                for(int i=0; i<k; i++){
                    if(C[i] >= mx) {
                        mult(pref[i], suff[i+1], v, temp_res);
                        ways_q = (ways_q + temp_res[v]) % MOD;
                    }
                }
            }
            ans = (ans * ways_q) % MOD;
        }
    }
    cout << ans << endl;
    for(int p : primes){
        C_arr[p].clear();
        req_v_arr[p] = 0;
    }
    primes.clear();
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    precomp();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}