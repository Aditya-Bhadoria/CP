#include <bits/stdc++.h>
using namespace std;
#define vint vector<int>
const int N = 1e5 + 10;
bool dfs_cycle(int vertex, int par, vint g[], bool vis[]){
    // Take action on vertex after entering the vertex
    vis[vertex] = true;
    bool isPos = false;
    for(int child : g[vertex]){
        if(vis[child] && child == par) continue;
        if(vis[child]) return true;
        // Take action on child before entering child node
        isPos |= dfs_cycle(child, vertex, g, vis);
        // Take action on child after exiting child node
    }
    return isPos; 
    // Take action on vertex before exiting the vertex
}
void cycle(){
    bool vis[N]; vector<int> g[N];
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y); 
        g[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        if(dfs_cycle(i, -1, g, vis)){
            cout << true; return;
        }
    }
    cout << false;
}
void dfs_parent(int ver, int p, vint &par, vint g[]){
    par[ver] = p;
    for(auto child : g[ver]){
        if(child == p) continue;
        dfs_parent(child, ver, par, g);
    }
}
vint path(int ver, vint&par, vint g[]){
    vint ans;
    while(ver != -1){
        ans.push_back(ver);
        ver = par[ver];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void lca(){
    vector<int> g[N], par(N);
    int n, m, n1, n2; cin >> n >> m >> n1 >> n2;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y); 
        g[y].push_back(x);
    }
    dfs_parent(1, -1, par, g);
    vector<int> path_x = path(n1, par, g);
    vector<int> path_y = path(n2, par, g);
    int lca = -1;
    for(int i=0; i<min(path_x.size(), path_y.size()); i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }
        else break;
    }
    cout << lca << endl;
}
void dfs_topo(int node, vector<vint>&adj, vint &vis, stack<int>&st){
    vis[node] = 1;
    for(auto child : adj[node]){
        if(!vis[child]){
            dfs_topo(child, adj, vis, st);
        }
    }
    st.push(node);
}
vint topoSort(int V, vector<vint>& edges) {
    vector<vint> adj(V);
    vint vis(V,0), ans;
    stack<int> st;
    for(auto it : edges) adj[it[0]].push_back(it[1]);
    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfs_topo(i, adj, vis, st);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
vint Kahn(int V, vector<vint>& edges) {
    vector<vint> adj(V);
    vint vis(V,0), ans, indeg(V,0);
    queue<int> q;
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        indeg[it[1]]++;
    }
    for(int i=0; i<V; i++) if(!indeg[i]) q.push(i);
    while(!q.empty()){
        int node = q.front();
        q.pop(); ans.push_back(node);
        for(auto child : adj[node]){
            indeg[child]--;
            if(!indeg[child]) q.push(child);
        }
    }
    return ans;
}
void dfs1_scc(int node, vector<int>&vis, vector<vector<int>>&adj, stack<int>&st){
    vis[node] = 1;
    for(auto child : adj[node]){
        if(!vis[child]) dfs1_scc(child, vis, adj, st);
    }
    st.push(node);
}
void dfs2_scc(int node, vector<int>&vis, vector<int> adjT[]){
    vis[node] = 1;
    for(auto child : adjT[node]){
        if(!vis[child]) dfs2_scc(child, vis, adjT);
    }
}
int kosaraju(vector<vector<int>> &adj) {
    int V = adj.size();
    vector<int> vis(V, 0);
    stack<int> st;
    for(int i=0; i<V; i++){
        if(!vis[i]) dfs1_scc(i, vis, adj, st);
    }
    vector<int> adjT[V];
    for(int i=0; i<V; i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            adjT[it].push_back(i);
        }
    }
    int scc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs2_scc(node, vis, adjT);
        }
    }
    return scc;
}
void dfs(int &timer, int node, int par, vector<int>&vis, vector<vector<int>> &adj,
        vector<int>&tin, vector<int>&low, vector<vector<int>>&bridges){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for(int it : adj[node]){
        if(it == par) continue;
        if(!vis[it]){
            dfs(timer, it, node, vis, adj, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node]){
                bridges.push_back({it, node});
            }
        }
        else{
            low[node] = min(low[node], low[it]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
    int timer = 1;
    vector<vector<int>> adj(n);
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    vector<int> tin(n), low(n);
    vector<vector<int>> bridges;
    dfs(timer, 0, -1, vis, adj, tin, low, bridges);
    return bridges;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    
    return 0;
}