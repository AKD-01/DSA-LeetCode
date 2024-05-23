class Solution {
    const int MX_NUM = 1000;
    int find(int index, vector<int>& nums, int k, vector<int> &cnt) {
        if(index == nums.size()) {
            return 1;
        }
        int ans = find(index + 1, nums, k, cnt); 
        int num = nums[index];

        if((num + k > MX_NUM || cnt[num + k] == 0) && (num - k < 1 || cnt[num - k] == 0)) {
            cnt[num]++;
            ans += find(index + 1, nums, k, cnt);
            cnt[num]--;
        }
        return ans;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> cnt(MX_NUM + 1, 0);
        return find(0, nums, k, cnt) - 1;
    }
};