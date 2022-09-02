class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zerocount = count(nums.begin(), nums.end(), 0);
        if(zerocount > 1) return vector<int>(nums.size());               
        for(auto val : nums) 
            if(val) product *= val;                                        
        for(auto& val : nums)
            if(zerocount) val = val ? 0 : product;                 
            else val = product/val;                                        
        return nums;
    }
};