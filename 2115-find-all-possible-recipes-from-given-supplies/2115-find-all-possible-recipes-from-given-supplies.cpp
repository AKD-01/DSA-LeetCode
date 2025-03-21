class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available(supplies.begin(), supplies.end());
        unordered_map<string, int> recipeIdx;
        unordered_map<string, vector<string>> graph;
        vector<int> inDegree(recipes.size(), 0);

        for (int i = 0; i < recipes.size(); i++) {
            recipeIdx[recipes[i]] = i;
        }

        for (int i = 0; i < recipes.size(); i++) {
            for (string& ing : ingredients[i]) {
                if (!available.count(ing)) {
                    graph[ing].push_back(recipes[i]);
                    inDegree[i]++;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < recipes.size(); i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<string> res;
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            res.push_back(recipes[idx]);

            for (string& dep : graph[recipes[idx]]) {
                if (--inDegree[recipeIdx[dep]] == 0) {
                    q.push(recipeIdx[dep]);
                }
            }
        }

        return res;
    }
};
