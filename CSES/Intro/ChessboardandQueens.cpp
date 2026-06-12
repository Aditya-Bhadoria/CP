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
const int DIM = 8;
void solve() {
    vector<vector<bool>> blocked(DIM, vector<bool>(DIM));
	for (int r = 0; r < DIM; r++) {
		string row; cin >> row;
		for (int c = 0; c < DIM; c++) { blocked[r][c] = row[c] == '*'; }
	}

	vector<int> queens(DIM);
	// Set the initial values to 0, 1...7
	iota(queens.begin(), queens.end(), 0);

	int valid_num = 0;
	do {
		bool works = true;
		// Check if any cells have been blocked off by the input
		for (int c = 0; c < DIM; c++) {
			if (blocked[queens[c]][c]) {
				works = false;
				break;
			}
		}

		// Check the diagonals from the top-left to the bottom-right
		vector<bool> taken(DIM * 2 - 1);
		for (int c = 0; c < DIM; c++) {
			// Check if the diagonal with sum has been taken
			if (taken[c + queens[c]]) {
				works = false;
				break;
			}
			taken[c + queens[c]] = true;
		}

		// Check the diagonals from the top-right to the bottom-left
		taken = vector<bool>(DIM * 2 - 1);
		for (int c = 0; c < DIM; c++) {
			// queens[c] - c can be negative; the DIM - 1 offsets that
			if (taken[queens[c] - c + DIM - 1]) {
				works = false;
				break;
			}
			taken[queens[c] - c + DIM - 1] = true;
		}

		if (works) { valid_num++; }
	} while (next_permutation(queens.begin(), queens.end()));

	cout << valid_num << endl;
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