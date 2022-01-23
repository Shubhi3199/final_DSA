// Just count the number of different connected components

class Solution {
public:
    void dfs_helper(int node, vector<vector<int>> &adj, vector<bool> &vis2) {
        vis2[node] = true;
        for (auto nbr: adj[node]) {
            if (!vis2[nbr]) dfs_helper(nbr, adj, vis2);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1; // As we need atleast n-1 edges to connect a graph with n vertices
        vector<bool> vis2(n, false);
        vector<vector<int>> adj(n, vector<int> ());
        for (auto edge: connections) {
            int x = edge[0], y = edge[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int num_connected_comp = 0;
        for (int i = 0; i < n; i++) {
            if (!vis2[i]) {
                dfs_helper(i, adj, vis2);
                num_connected_comp++;
            }
        }
        return num_connected_comp - 1;
    }
};
