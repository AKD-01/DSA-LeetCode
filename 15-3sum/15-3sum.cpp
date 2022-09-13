class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<=n-3;i++) {
            int j=i+1;
            int k=n-1;
            while(j<k) {
            int currsum=nums[i];
            currsum+=nums[j];
            currsum+=nums[k];
            if(currsum==0) {
                result.push_back({nums[i],nums[j],nums[k]});
                while(j<k && nums[j]==nums[j+1]) j++;
                while(j<k && nums[k]==nums[k-1]) k--;
                j++;
                k--;
            }
            else if(currsum>0) k--;
            else j++;
            }
            while(i+1<n-2 && nums[i]==nums[i+1]) i++;
        }
        return result;
    }
};