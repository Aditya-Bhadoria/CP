#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

const int MAX_N = 2048;
int tree[MAX_N][MAX_N];
int padded_n;

// query across columns (X-axis)
int query_x(int r_node, int c_node, int c_low, int c_high, int qx1, int qx2) {
    if (qx1 <= c_low && c_high <= qx2) {
        return tree[r_node][c_node];
    }
    if (c_high < qx1 || qx2 < c_low) {
        return 0;
    }
    int mid = (c_low + c_high) / 2;
    return query_x(r_node, 2 * c_node, c_low, mid, qx1, qx2) +
           query_x(r_node, 2 * c_node + 1, mid + 1, c_high, qx1, qx2);
}

// query across rows (Y-axis)
int query_y(int r_node, int r_low, int r_high, int qy1, int qy2, int qx1, int qx2) {
    if (qy1 <= r_low && r_high <= qy2) {
        // When the row interval matches perfectly, query its internal column tree
        return query_x(r_node, 1, 0, padded_n - 1, qx1, qx2);
    }
    if (r_high < qy1 || qy2 < r_low) {
        return 0;
    }
    int mid = (r_low + r_high) / 2;
    return query_y(2 * r_node, r_low, mid, qy1, qy2, qx1, qx2) +
           query_y(2 * r_node + 1, mid + 1, r_high, qy1, qy2, qx1, qx2);
}

void solve() {
    int n, q; cin >> n >> q;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    padded_n = n;
    while (__builtin_popcount(padded_n) != 1) {
        padded_n++;
    }
    // 1) Initialize the leaves of the 2D tree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tree[padded_n + i][padded_n + j] = (grid[i][j] == '*');
        }
    }
    // 2) Build iteratively: first fill the column segments for each base row
    for (int i = 0; i < padded_n; i++) {
        for (int j = padded_n - 1; j >= 1; j--) {
            tree[padded_n + i][j] = tree[padded_n + i][2 * j] + tree[padded_n + i][2 * j + 1];
        }
    }
    // 3) Build iteratively: combine rows together
    for (int i = padded_n - 1; i >= 1; i--) {
        for (int j = 1; j < 2 * padded_n; j++) {
            tree[i][j] = tree[2 * i][j] + tree[2 * i + 1][j];
        }
    }
    // 4) Process Queries
    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;
        cout << query_y(1, 0, padded_n - 1, y1, y2, x1, x2) << '\n';
    }
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