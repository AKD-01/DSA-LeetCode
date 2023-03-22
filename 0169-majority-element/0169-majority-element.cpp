class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        //moore voting algorithm
        /*int candidate=0;
        int count=0;
        for(int num: nums) {
            if(count==0) candidate=num;
            if(num==candidate) count++;
            else count--;
        }
        return candidate;*/
        //Better approach using hasing - TC-O(nlogn)+O(n) SC-O(n) 
        map<int,int> m;
        for(int i=0; i<n; i++) {
            m[nums[i]]++;
        }
        for(auto it: m) {
            if(it.second>n/2) return it.first;
        }
        return -1;
        //Brute force approach TC-O(n*n) SC-O(1)
        /*for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(nums[j]==nums[i]) count++;
            }
            if(count > n/2) return nums[i];
        }
        return -1;*/
    }
};