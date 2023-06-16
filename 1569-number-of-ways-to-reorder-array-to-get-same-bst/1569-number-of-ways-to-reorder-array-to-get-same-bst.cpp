class Solution {
public:
     int numOfWays(vector<int>& nums) {
        long long mod = 1e9 + 7;
		int n = nums.size();
        
		// Pascal triangle
        table.resize(n + 1);
        for(int i = 0; i < n + 1; ++i){
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }
        
        long long ans = dfs(nums, mod);
        return ans % mod - 1;
    }
    
private:
    vector<vector<long long>> table;
    long long dfs(vector<int> &nums, long long mod){
        int n = nums.size();
        if(n <= 2) return 1;
        
		// find left sub-sequence elements and right sub-sequence elements
        vector<int> left, right;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
		
		// recursion with left subtree and right subtree
        long long left_res = dfs(left, mod) % mod;
        long long right_res = dfs(right, mod) % mod;
		
		// look up table and multiple them together
		int left_len = left.size(), right_len = right.size();
        return (((table[n - 1][left_len] * left_res) % mod) * right_res) % mod;
    }
};