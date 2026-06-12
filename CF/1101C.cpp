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

#define x first
#define y second

typedef pair<int, int> pt;

int n;
vector< pair<pt, int> > segs;

bool cmp(const pair<pt, int> &a, const pair<pt, int> &b) {
	if(a.x.y != b.x.y)
		return a.x.y < b.x.y;
	if(a.x.x != b.x.x)
		return a.x.x < b.x.x;
	return a.y < b.y;
}

void solve() {
    int n; cin >> n;
    segs.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> segs[i].x.x >> segs[i].x.y;
		segs[i].y = i;
	}
	sort(segs.begin(), segs.end(), cmp);
	
	int mn = segs[n - 1].x.x;
	for(int i = n - 2; i >= 0; i--) {
		if(segs[i].x.y < mn) {
			vector<int> ts(n, 2);
			for(int id = 0; id <= i; id++)
				ts[segs[id].y] = 1;
			
			for(int t : ts)
				cout << t << ' ';
			cout << '\n';
				
			return;
		}
		mn = min(mn, segs[i].x.x);
	}
	cout << -1 << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}