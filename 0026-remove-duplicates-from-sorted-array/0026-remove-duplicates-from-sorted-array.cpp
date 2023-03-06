class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //brute force approach tc-O(nlogn + n) and sc-O(n)
        set<int> s;
        for(auto it : nums) {
            s.insert(it);
        }
        int index=0;
        for(auto it : s) {
            nums[index] = it;
            index++;
        }
        return index;
    }
};