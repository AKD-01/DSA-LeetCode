class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());

        for (int num : nums2) {
            if (set1.contains(num)) {
                return num;
            }
        }

        return -1;
    }
};