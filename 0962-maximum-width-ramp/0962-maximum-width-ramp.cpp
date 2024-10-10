class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stac;
        stac.push(0);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[stac.top()]>nums[i])stac.push(i);
            
        }

        int maxWidth=0;
        for(int j=nums.size()-1;j>=0;j--)
        {
            while(!stac.empty() && nums[j]>=nums[stac.top()])
            {
                maxWidth=max(maxWidth , j-stac.top());
                stac.pop();
            }
        }

        return maxWidth;
    }
};