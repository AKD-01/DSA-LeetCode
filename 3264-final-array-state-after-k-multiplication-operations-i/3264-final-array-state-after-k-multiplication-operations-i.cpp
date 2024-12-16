class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
       priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        for (int i = 0; i < nums.size(); ++i) {
            pq.push({(long long)nums[i], i}); 
        }

        while (k--) {
            auto [value, idx] = pq.top();
            pq.pop();
            
            value *= mul; 
            nums[idx] = value;
            
            pq.push({value, idx}); 
        }

        return nums;  
    }
};