class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto edge : edges) indegree[edge[1]]++;
        
        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] != 0) continue;     
            if (champion != -1) return -1;      
            champion = i;
        }
        return champion;
    }
};