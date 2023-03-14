class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        //Optimized TC-O(2n) and SC=O(1)
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
       //Brute TC-O(n+k) SC-O(k)
        /*vector<int> temp;
        int n=nums.size();
        k=k%n;
        for(int i=n-k;i<n;i++) {
            temp.push_back(nums[i]);
        }
        //Shifting
        for(int i=n-1;i>=k;i--) {
            nums[i]=nums[i-k];        
        }
        //put back temp elements
        for(int i=0;i<k;i++) {
            nums[i]=temp[i];
        }*/
    }
};