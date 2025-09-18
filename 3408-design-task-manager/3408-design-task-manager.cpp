#define pii pair<int,int>

class TaskManager {
public:

    unordered_map<int,pii> mp;
    priority_queue<pii> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto i:tasks){
            mp[i[1]] = {i[2],i[0]};
            pq.push({i[2],i[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority, userId};
        pq.push({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId] = {newPriority, mp[taskId].second};
        pq.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        mp[taskId] = {-1,-1};
    }
    
    int execTop() {
        if(pq.empty()) return -1;
        pii top = pq.top();
        while(!pq.empty() && top.first != mp[top.second].first){
            pq.pop();
            top = pq.top();
        }
        if(pq.empty()) return -1;
        int ans = mp[top.second].second;
        mp[top.second] = {-1,-1};
        pq.pop();
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */