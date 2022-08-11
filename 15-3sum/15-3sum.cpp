class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            int t=-x;
            int s=i+1, e=n-1;
            while(s<e){
                int sum=nums[s]+nums[e];
                if(sum==t) {
                ans.push_back({nums[i],nums[s],nums[e]});
                while(s<e&&nums[s]==nums[s+1]) s++;
                while(s<e&&nums[e]==nums[e-1]) e--;
                s++;
                e--;
                }
                else if(sum>t) e--;
                else s++;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};