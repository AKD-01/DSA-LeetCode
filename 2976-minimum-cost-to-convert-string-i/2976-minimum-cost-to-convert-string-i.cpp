class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> adjacencyList(26);

        int conversionCount = original.size();
        for (int i = 0; i < conversionCount; i++) {
            adjacencyList[original[i] - 'a'].push_back(
                {changed[i] - 'a', cost[i]});
        }

        vector<vector<long long>> minConversionCosts(26, vector<long long>(26));
        for (int i = 0; i < 26; i++) {
            minConversionCosts[i] = dijkstra(i, adjacencyList);
        }

        long long totalCost = 0;
        int stringLength = source.length();
        for (int i = 0; i < stringLength; i++) {
            if (source[i] != target[i]) {
                long long charConversionCost =
                    minConversionCosts[source[i] - 'a'][target[i] - 'a'];
                if (charConversionCost == -1) {
                    return -1; 
                }
                totalCost += charConversionCost;
            }
        }
        return totalCost;
    }

private:
    vector<long long> dijkstra(
        int startChar, const vector<vector<pair<int, int>>>& adjacencyList) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            priorityQueue;

        priorityQueue.push({0, startChar});

        vector<long long> minCosts(26, -1);

        while (!priorityQueue.empty()) {
            auto [currentCost, currentChar] = priorityQueue.top();
            priorityQueue.pop();

            if (minCosts[currentChar] != -1 &&
                minCosts[currentChar] < currentCost)
                continue;

            for (auto& [targetChar, conversionCost] :
                 adjacencyList[currentChar]) {
                long long newTotalCost = currentCost + conversionCost;

                if (minCosts[targetChar] == -1 ||
                    newTotalCost < minCosts[targetChar]) {
                    minCosts[targetChar] = newTotalCost;
                    priorityQueue.push({newTotalCost, targetChar});
                }
            }
        }
        return minCosts;
    }
};