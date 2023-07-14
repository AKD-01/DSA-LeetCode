class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> lengths;
        int result=1;
        for(int &i:arr)
            result=max(result,lengths[i]=1+lengths[i-difference]); //Length of AP ending with 'i' with difference of 'difference' will be 1 + length of AP ending with 'i-difference'. result stores Max at each end
        return result;
    }
};