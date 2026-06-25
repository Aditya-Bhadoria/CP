#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>

const int INF = 1e9;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char dir_chars[] = {'U', 'D', 'L', 'R'};

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    pair<int, int> start_A;
    vector<vint> monst_t(n, vint(m, INF)), my_t(n, vint(m, INF)), p_move(n, vint(m, -1));
    queue<pair<int, int>> mq;
    for(int i=0; i<n; i++){
        cin >> grid[i];
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'M'){
                monst_t[i][j] = 0;
                mq.push({i, j});
            }
            else if (grid[i][j] == 'A'){
                start_A = {i, j};
                my_t[i][j] = 0;
            }
        }
    }
    // 1) Multi-source BFS for Monsters
    while(!mq.empty()){
        auto [r, col] = mq.front();
        mq.pop();
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#'){
                if(monst_t[nr][nc] == INF){
                    monst_t[nr][nc] = monst_t[r][col] + 1;
                    mq.push({nr, nc});
                }
            }
        }
    }
    // 2) Single-source BFS for Player A
    queue<pair<int, int>> aq;
    aq.push(start_A);
    while(!aq.empty()){
        auto [r, col] = aq.front();
        aq.pop();
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#'){
                if(my_t[nr][nc] == INF){
                    my_t[nr][nc] = my_t[r][col] + 1;
                    p_move[nr][nc] = i; // Store index of the move direction
                    aq.push({nr, nc});
                }
            }
        }
    }
    // 3) Search boundary tiles for a safe exit
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                if(my_t[i][j] < monst_t[i][j]){
                    cout << "YES\n";
                    // Backtrack to build path string
                    string path = "";
                    int curr_r = i, curr_c = j;
                    while(curr_r != start_A.first || curr_c != start_A.second){
                        int move_idx = p_move[curr_r][curr_c];
                        path += dir_chars[move_idx];
                        // Reverse the direction to step backwards
                        curr_r -= dr[move_idx];
                        curr_c -= dc[move_idx];
                    }
                    reverse(path.begin(), path.end());
                    cout << path.length() << "\n" << path << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
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