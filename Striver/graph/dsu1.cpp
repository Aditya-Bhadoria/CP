#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
#define vll vector<ll>
class DSU {
    vector<int> parent, size, rank;
public:
    // Constructor: initialize DSU for n elements (1-based indexing)
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    // Optional: create a new set containing only v
    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    // Find the representative with path compression
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    // Union two sets by size
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    // Union two sets by rank
    void uniteByRank(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) parent[a] = b;
            else if (rank[b] < rank[a]) parent[b] = a;
            else{
                parent[b] = a;
                rank[a]++;
            }
        }
    }
    // Get size of the set containing v
    int get_size(int v) {
        return size[find(v)];
    }
    // Get rank of the set containing v
    int get_rank(int v){
        return rank[find(v)];
    }
};
int kruskal(int V, vector<vector<int>> adj[]){
    vector<pair<int, pair<int,int>>> edges;
    vector<pair<int,int>> mst;
    for(int i=0; i<V; i++){
        for(auto it : adj[i]){
            int node = i;
            int edW = it[1];
            int child = it[0];
            edges.push_back({edW, {node, child}});
        }
    }
    DSU ds(V);
    sort(edges.begin(), edges.end());
    int mstWt = 0;
    for(auto it : edges){
        int wt = it.first, node = it.second.first;
        int child = it.second.second;
        if(ds.find(node) != ds.find(child)){
            mstWt += wt;
            ds.unite(node, child); // also generates tree
            mst.push_back({node, child});
        }
    }
    return mstWt;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    
    return 0;
}