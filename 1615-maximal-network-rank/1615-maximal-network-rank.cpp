class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        // Building the graph (adjacency list). 
        for (const auto& road: roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        
        int maximal = 0;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Sum of neighbors (connected cities) of both cities. 
                int network_rank = graph[i].size() + graph[j].size();
                
                // Reduce the rank by 1 in case the cities are connected to each other.
                if (graph[j].count(i)) {
                    --network_rank;
                }
                
                // Maximal network rank is the maximum network rank possible.
                maximal = max(maximal, network_rank);
            }
            
        }
        return maximal;
    }
};