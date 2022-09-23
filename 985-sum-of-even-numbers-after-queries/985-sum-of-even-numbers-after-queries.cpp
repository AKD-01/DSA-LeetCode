class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evensum=0, n=nums.size(); 
        vector<int> result;
        for(int i=0;i<n;i++) {
            if(nums[i]%2==0) evensum+=nums[i];
        }
        for(int i=0;i<n;i++) {
            int index=queries[i][1];
            int val=queries[i][0];
            if(nums[index]%2==0) evensum-=nums[index];
            nums[index]+=val;
            if(nums[index]%2==0) evensum+=nums[index];
            result.push_back(evensum);
        }
        return result;
    }
};