class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //optimized approach tc-O(n) sc-O(1) as two pointers approach
        int i=0, n=nums.size();
        for(int j=1; j<n; j++) {
            if(nums[i] != nums[j]) {
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};

//brute force approach tc-O(nlogn + n) and sc-O(n)
        /*set<int> s;
        for(auto it : nums) {
            s.insert(it);
        }
        int index=0;
        for(auto it : s) {
            nums[index] = it;
            index++;
        }
        return index;*/