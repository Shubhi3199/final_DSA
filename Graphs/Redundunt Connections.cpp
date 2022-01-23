class Solution {
public:
    int find_parent(int node, vector<int> &parent) {
        if (parent[node] == -1) return node;
        return parent[node] = find_parent(parent[node], parent);
    }
    void unite(int node1, int node2, vector<int> &parent, vector<int> &rank) {
        int par1 = find_parent(node1, parent);
        int par2 = find_parent(node2, parent);
        if (par1 == par2) return;
        if (rank[par1] >= rank[par2]) {
            parent[par2] = par1;
            rank[par1] += rank[par2];
        }
        else {
            parent[par1] = par2;
            rank[par2] += rank[par1];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // num of nodes in the tree
        vector<int> parent(n+1, -1);
        vector<int> rank(n+1, 1);
        for (vector<int> edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            if (find_parent(node1, parent) == find_parent(node2, parent)) {
                // we have a cycle as they both have the same parents
                return edge;
            }
            unite(node1, node2, parent, rank);
        }
        return {};
    }
};
