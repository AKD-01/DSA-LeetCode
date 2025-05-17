class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0, count1=0, count2=0, n=nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]==0) count0++;
            if(nums[i]==1) count1++;
            else count2++;
        }
        for(int i=0; i<count0; i++) {
            nums[i]=0;
        }
        for(int i=count0; i<count0+count1; i++) {
            nums[i]=1;
        }
        for(int i=count0+count1; i<n; i++) {
            nums[i]=2;
        }
    }
};
//Brute Approach - Use any sorting algo - used merge sort
/*
        int low=0,high=nums.size()-1;
        mergesort(nums,low,high);
 void merge(vector<int> &nums, int low, int mid, int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        while(left<=mid and right<=high) {
            if(nums[left]<nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high) {
            temp.push_back(nums[right]);
            right++;
        }
        int k=0;
        for(int i=low;i<=high; i++) {
            nums[i]=temp[k];
            k++;
        }
    }
    void mergesort(vector<int> &nums, int low, int high) {
        if(low>=high) return;
        int mid = low+(high-low)/2;
        mergesort(nums, 0, mid);
        mergesort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
*/