class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Optimized Approach TC-0(N) SC-O(1)
        int j=-1;
        int n=nums.size();
        for(int i=0; i<n; i++) {
           if(nums[i]==0) {
               j=i;
               break;
           } 
        }
        if(j==-1)  return;
        for(int i=j+1;i<n;i++) {
            if(nums[i]!=0) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        //Brute force approach TC-O(2N) SC-O(x) x-non zero elements
        /*vector<int> temp;
        int n =  nums.size();
        for(int val: nums) {
            if(val!=0) temp.push_back(val);
        }
        int s=temp.size();
        for(int i=0; i<s; i++) {
            nums[i] = temp[i];
        }
        for(int i=s; i<n; i++) {
            nums[i]=0;
        }*/
    }
};