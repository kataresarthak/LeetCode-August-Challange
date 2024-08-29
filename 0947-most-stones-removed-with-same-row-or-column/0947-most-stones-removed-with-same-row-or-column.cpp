class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, unordered_set<int>& visited) {
        visited.insert(node);
        for (int neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);  // adjacency list

        // Build the graph
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        unordered_set<int> visited;
        int numComponents = 0;

        // Find the number of connected components
        for (int i = 0; i < n; ++i) {
            if (visited.find(i) == visited.end()) {
                dfs(i, adj, visited);
                numComponents++;
            }
        }

        return n - numComponents;
    }
};