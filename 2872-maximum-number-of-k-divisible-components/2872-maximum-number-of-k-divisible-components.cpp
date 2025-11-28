class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {
        vector<int> adjList[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        int componentCount = 0;

        dfs(0, -1, adjList, values, k, componentCount);

        return componentCount;
    }

private:
    int dfs(int currentNode, int parentNode, vector<int> adjList[],
            vector<int> &nodeValues, int k, int &componentCount) {
        int sum = 0;

        for (auto neighborNode : adjList[currentNode]) {
            if (neighborNode != parentNode) {
                sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
                           componentCount);
                sum %= k;  
            }
        }

        sum += nodeValues[currentNode];

        sum %= k;
        if (sum == 0) componentCount++;

        return sum;
    }
};