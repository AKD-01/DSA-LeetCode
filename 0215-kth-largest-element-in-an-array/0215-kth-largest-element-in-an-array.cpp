class Solution {
public:
    int partition(vector<int> &nums, int s, int e) {
        int pivot=nums[e];
        int i=s-1;
        for(int j=s;j<e;j++) {
            if(nums[j]<pivot) {
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[e]);
        return i+1;
    }
    int quickselect(vector<int>& nums, int s, int e, int k) {
        int p=partition(nums,s,e);
        if(p==k) {
            return nums[p];
        }
        else if(p<k) {
            return quickselect(nums, p+1,e,k);
        }
        else {
            return quickselect(nums,s,p-1,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return quickselect(nums,0,n-1,n-k);
    }
};