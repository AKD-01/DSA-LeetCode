class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // group the isolated item by itself 
        for(int i = 0; i < n; ++i){
            if(group[i] == -1)
                group[i] = m++;
        }
        // build graph
        vector<unordered_set<int>> graphGroup(m), graphItem(n);
        vector<int> inGroup(m), inItem(n);
        for(int i = 0; i < n; i++) {
            int to_group = group[i];
            for(int from : beforeItems[i]) {
                int from_group = group[from];
                if(from_group != to_group && !graphGroup[from_group].count(to_group)) {
                    graphGroup[from_group].insert(to_group);
                    inGroup[to_group]++;
                }
                if(!graphItem[from].count(i)) {
                    graphItem[from].insert(i);
                    inItem[i]++;
                }
            }
        }
        
        // topo sort
        vector<int> group_sorted = topoSort(graphGroup, inGroup);
        vector<int> item_sorted = topoSort(graphItem, inItem);
        
        if(group_sorted.empty() || item_sorted.empty()) return {};

        vector<vector<int>> group2item(m);
        for(auto item : item_sorted){
            group2item[group[item]].push_back(item);
        }
        
        vector<int> ans;
        for(int group_id : group_sorted) {
            for(int item : group2item[group_id]) {
                ans.push_back(item);
            }
        }
        
        return ans;
    }
    
    vector<int> topoSort(vector<unordered_set<int>>& graph, vector<int>& indegree) {
        vector<int> ans;
        queue<int> q;
        for(int i =  0; i <indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            
            ans.push_back(t);
            
            for(int next : graph[t]) {
                --indegree[next];
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        for(int i =  0; i < indegree.size(); i++) {
            if(indegree[i] > 0) return {};
        }
        
        return ans;
    }
};