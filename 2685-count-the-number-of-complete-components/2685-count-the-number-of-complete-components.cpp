class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        unordered_map<string, int> componentFreq;

        for (int vertex = 0; vertex < n; vertex++) {
            graph[vertex].push_back(vertex);
        }

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int vertex = 0; vertex < n; vertex++) {
            vector<int> neighbors = graph[vertex];
            sort(neighbors.begin(), neighbors.end());

            string key;
            for (int num : neighbors) {
                key += to_string(num) + ",";
            }
            componentFreq[key]++;
        }

        int completeCount = 0;
        for (const auto& entry : componentFreq) {
            int size = count(entry.first.begin(), entry.first.end(), ',');
            if (size == entry.second) {
                completeCount++;
            }
        }

        return completeCount;
    }
};