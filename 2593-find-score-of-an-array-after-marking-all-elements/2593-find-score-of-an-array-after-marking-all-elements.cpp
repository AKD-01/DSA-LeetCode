class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        int n=nums.size(),c=0;
        unordered_map<int,bool> mp;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }  
        while(n--){
            auto ele = pq.top();
            pq.pop();
            int val = ele.first, ind = ele.second;
            if(mp.find(ind) == mp.end()){
                ans += val;
                mp[ind] = 1;
                mp[ind-1] = 1;
                mp[ind+1] = 1;
            }
        }
        return ans;   
    }
};