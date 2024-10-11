class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int target = times[targetFriend][0];
        
        sort(times.begin(),times.end());
        int n = times.size();
        
        priority_queue<int,vector<int>, greater<int> > pq_chair;
        
        for(int i = 0; i < n; i++)
            pq_chair.push(i);
        
    
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>> > pq_leaving;
        
        for(auto v : times){
            int arrival = v[0], dep = v[1];
            while(!pq_leaving.empty() && pq_leaving.top().first <= arrival){
                pair<int,int> p = pq_leaving.top();
                pq_leaving.pop();
                pq_chair.push(p.second);
            }
            int chair = pq_chair.top();
            pq_chair.pop();
            pq_leaving.push({dep,chair});
            if(arrival == target)
                return chair;
        }
        return -1;
    }
};