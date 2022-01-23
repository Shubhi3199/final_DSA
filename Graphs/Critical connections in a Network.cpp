// Bridges in grph - If my nbr's least discovery tiem is greater than my discovery time, that means there exists no beackedge to my nbr and if I remove this only edge b/w
// the cur_node and the nbr, we'll have more than 1 components formed
class Solution {
public:
    void dfs(int node, int parent, int &time, vector<int> &disc_time, vector<int> &lowest_disc_time, vector<int> *graph, vector<vector<int>> &res) {
        
        disc_time[node] = lowest_disc_time[node] = time++; // setting the discovery time of the node when we visit an unvisited node in a dfs traversal (also would act as visited as disc_time != -1)
        for (int nbr: graph[node]) {
            if (nbr == parent) continue;
            if (disc_time[nbr] == -1) {
                dfs(nbr, node, time, disc_time, lowest_disc_time, graph, res);
                if (lowest_disc_time[nbr] > disc_time[node]) {
                    // i.e., there's no way to reach the nbr node before reaching the parent node, i.e. there is no backedge from nbr node to one of the ancestor nodes and hence the current edge will act as a bridge
                    res.push_back({node, nbr});
                }
            }
            
            // Now, we have already visited the nbr node and it it's not the parent
            // therefore, there must exist another way of reaching the current node apart from parent (found a back-edge)
            // setting the cur node's lowest disc time to lowest of it;s nbrs(except parent) disc time
            lowest_disc_time[node] = min(lowest_disc_time[node], lowest_disc_time[nbr]);
            
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[n];
        for (vector<int> edge: connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> disc_time(n, -1); // time when the node is first discovered in a dfs traversal
        vector<int> lowest_disc_time(n, -1); // discovery time of any nbr node (except parent) which is lesser than the current node's discovery time {meaning that the current node can be visited from any other node also apart from the parent node i.e. there exists a backedge to the current node}
        
        vector<vector<int>> res;
        int time = 0;
        dfs(0, -1, time, disc_time, lowest_disc_time, graph, res);
        return res;
    }
};
