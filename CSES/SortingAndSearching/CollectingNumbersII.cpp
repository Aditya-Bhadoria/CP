#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;
using ll = long long;
using ull=unsigned long long;

#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pii pair<int,int>
#define pb push_back
#define out(v) for(auto &i: v) cout<<i<<" ";cout << endl;
#define in(v) for(auto &i: v) cin>>i;
#define inn(v,n) for(int i=0;i<n;i++) cin>>v[i];
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
typedef tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
//p.find_by_order - value at given index
//p.order_of_key - index of given key

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a*b/gcd(a,b); }

ll pow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

ll pow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}

vector<int> collectingnumbersII(int n, int m, vector<int>& values,
                    vector<vector<int> >& swaps){
    // Make the array 1-indexed
    values.insert(values.begin(), 0);
    vector<int> res;
    vector<int> position(n + 1);

    // Store the positions of the values
    for (int i = 1; i <= n; i++)
        position[values[i]] = i;

    // Calculate the initial number of rounds
    int count = 1;
    for (int i = 1; i < n; i++)
        // Increase the count if there is an inversion i.e.
        // if the position of i is greater than the position
        // of i+1
        count += (position[i] > position[i + 1]);

    // Declare a set to store the pairs of values that will
    // be updated
    set<pair<int, int> > updatedPairs;

    for (int i = 0; i < m; i++) {
        // Declare two integers l and r to store the
        // positions to be swapped
        int l = swaps[i][0], r = swaps[i][1];

        // Insert the pairs of values that will be updated
        // into the set
        if (values[l] + 1 <= n)
            updatedPairs.insert(
                { values[l], values[l] + 1 });
        if (values[l] - 1 >= 1)
            updatedPairs.insert(
                { values[l] - 1, values[l] });
        if (values[r] + 1 <= n)
            updatedPairs.insert(
                { values[r], values[r] + 1 });
        if (values[r] - 1 >= 1)
            updatedPairs.insert(
                { values[r] - 1, values[r] });

        // Update the count before the swap
        for (auto swapped : updatedPairs)
            // Subtract from the count, the inversions
            // formed by our current set as there may be
            // some elements that don’t form an inversion
            // after the swap and if they form they'll be
            // counted.
            count -= position[swapped.first]
                     > position[swapped.second];

        // Perform the swap
        swap(values[l], values[r]);

        // Update the position of the value at position l
        position[values[l]] = l;
        // Update the position of the value at position r
        position[values[r]] = r;

        // Update the count after the swap
        for (auto swapped : updatedPairs)
            // Count and add the inversions by adjacent
            // elements to our existing count.
            count += position[swapped.first]
                     > position[swapped.second];

        // Add the count to the result vector.
        res.push_back(count);

        // Clear the set for the next operation
        updatedPairs.clear();
    }
    // Return result
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    vint val(n); in(val);
    vector<vint> swaps(m, vint(2));
    for(int i=0; i<m; i++){
        cin >> swaps[i][0] >> swaps[i][1];
    }
    vint ans = collectingnumbersII(n, m, val, swaps);
    
    for(auto it : ans) cout << it << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}