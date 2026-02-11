#include <bits/stdc++.h>
using namespace std;
#define vint vector<int>
const int N = 1e3 + 10;
const int INF = 1e9 + 5;
int getX(string s){ return s[0]-'a'; }
int getY(string s){ return s[1]-'1'; }
bool isValid(int x,int y,int n,int m){return !(x<0||y<0||x>=n||y>=m);}
void nakanj(){
    int t; cin >> t;
    vector<pair<int,int>> movements = {
        {1, 2}, {-1, 2},
        {2, 1}, {-2, 1},
        {1, -2}, {-1, -2},
        {2, -1}, {-2, -1}
    };
    while(t--){
        string s1, s2; cin >> s1 >> s2;
        vector<vector<int>> chess(8, vector<int>(8,INF));
        vector<vector<int>> vis(8, vector<int>(8, 0));
        int sourceX = getX(s1), sourceY = getY(s1);
        int destX = getX(s2), destY = getY(s2);
        // cout<<sourceX<<" "<<sourceY<<" "<<destX<<" "<<destY<<endl;
        queue<pair<int, int>> q;
        q.push({sourceX, sourceY});
        chess[sourceX][sourceY] = 0;
        vis[sourceX][sourceY] = 1;
        while(!q.empty()){
            pair<int, int> v = q.front();
            int x = v.first, y = v.second;
            q.pop();
            for(auto move : movements){
                int childX = move.first + x;
                int childY = move.second + y;
                if(!isValid(childX, childY, 8, 8)) continue;
                if(!vis[childX][childY]){
                    q.push({childX, childY});
                    chess[childX][childY] = chess[x][y] + 1;
                    vis[childX][childY] = 1;
                }
            }
        }
        cout << chess[destX][destY] << endl;
    }
}
int bfs01(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> g(n+1);
    vector<int> lvl(n+1, INF);
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        if(x == y) continue;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }
    deque<int> q;
    q.push_back(1);
    lvl[1] = 0;
    while(!q.empty()){
        int cur_v = q.front();
        q.pop_front();
        for(auto child : g[cur_v]){
            int child_t = child.first;
            int wt = child.second;
            if(lvl[cur_v]+wt < lvl[child_t]){
                lvl[child_t] = lvl[cur_v] + wt;
                if(wt == 1){
                    q.push_back(child_t);
                }
                else q.push_front(child_t);
            }
        }
    }
    return lvl[n] == INF ? -1 : lvl[n];
}
void multiSourceBFS(){
    int t; cin >> t;
    vector<pair<int,int>> movements = {
        {1, 1}, {-1, 1},
        {1, -1}, {-1, -1},
        {1, 0}, {-1, 0},
        {0, 1}, {0, -1}
    };
    while(t--){
        int n, m, maxi = 0; cin >> n >> m;
        vector<vector<int>> g(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> g[i][j];
                maxi = max(maxi, g[i][j]);
            }
        }
        vector<vector<int>> lvl(n, vector<int>(m,INF));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(g[i][j] == maxi){
                    q.push({i,j});
                    lvl[i][j] = 0; vis[i][j] = 1;
                }
            }
        } 
        maxi = 0;
        while(!q.empty()){
            pair<int, int> v = q.front();
            int x = v.first, y = v.second;
            q.pop();
            for(auto move : movements){
                int childX = move.first + x;
                int childY = move.second + y;
                if(!isValid(childX, childY, n, m)) continue;
                if(!vis[childX][childY]){
                    q.push({childX, childY});
                    lvl[childX][childY] = lvl[x][y] + 1;
                    vis[childX][childY] = 1;
                    maxi = max(maxi, lvl[childX][childY]);
                }
            }
        }
        cout << maxi << endl;
    }
}
int dijkstra(){
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);
    vector<pair<int, int> > g[N]; // node, wt
    using T = pair<int, int>;
    priority_queue<T, vector<T>, greater<T>> pq; // wt, node
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, wt; cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }
    pq.push({0, 1}); dist[1] = 0;
    while(!pq.empty()){
        auto node = pq.top();
        int dis = node.first;
        int v = node.second;
        pq.pop();
        for(auto child : g[v]){
            int wt = child.second;
            int child_v = child.first;
            if(dist[v]+wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                pq.push({dist[child_v], child_v});
            }
        }
    } // O(V + ELog(V))
    int ans = 0;
    for(int i=1; i<=n; i++){
        cout << dist[i] << " ";
        if(dist[i] == INF) return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}
void FloydWarshall(){
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for(int i=0; i<N; i++){ dist[i][i] = 0; }
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, z; cin >> x >> y >> z;
        dist[x][y] = z;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    } // O(N^3), can handle -ve wts but not overall -ve cycle
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] == INF){ cout << "I ";}
            else cout << dist[i][j] << " ";
        } cout << endl;
    }
}
bool bfsBipartite(vector<vector<int>>&g, vector<int>&color, int src){
    queue<int> q;
    q.push(src);
    color[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : g[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, -1);
    bool check = true;
    for(int i=0; i<V; i++){
        if(color[i] == -1){
            check &= bfsBipartite(graph, color, i);
        }
    }
    return check;
}
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src){
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    for(int i=0; i<V-1; i++){
        for(auto it : edges){
            int u = it[0], v = it[1], wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    for(auto it : edges){
        int u = it[0], v = it[1], wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    return dist;
}
int mst(int V, vector<vector<int>> adj[]){
    using T = vector<int>;
    priority_queue<T, vector<T>, greater<T>> q;
    vector<int> vis(V, 0);
    vector<pair<int,int>> edges; // mst tree
    q.push({0, 0, -1}); // wt, node, par
    int sum = 0;
    while(!q.empty()){
        auto it = q.top(); q.pop();
        int wt = it[0], node = it[1], par = it[2];
        if(vis[node]) continue;
        vis[node] = 1;
        if(par != -1) edges.push_back({node, par});
        sum += wt;
        for(auto child : adj[node]){
            int chl = child[0], edw = child[1];
            if(!vis[chl]) q.push({edw, chl, node});
        }
    }
    return sum;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    
    return 0;
}