class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       long long int x_or = nums[0], x = 0,  y = 0, n = nums.size(); 
        for(int i = 1; i < n; i++)  x_or ^= nums[i];
        long long int sbn = x_or & ~(x_or - 1); 
        for(int i = 0; i < n; i++){
            if(sbn & nums[i]){
                x ^= nums[i];
            }
            else y ^= nums[i];
        }
        return {(int)x, (int)y};
    }
};