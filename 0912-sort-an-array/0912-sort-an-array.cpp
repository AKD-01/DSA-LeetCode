class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      mergesort(nums,0,nums.size()-1);
      return nums;
    }
    void mergesort(vector<int> &nums,int s, int e) {
        //basecase
        if(s>=e) {
            return;
        }
        //recursive call
        int mid=(s+e)/2;
        mergesort(nums,s,mid);
        mergesort(nums,mid+1,e);
        return merge(nums,s,e);
    }
    void merge(vector<int> &nums, int s, int e){
        int i=s;
        int m=(s+e)/2;
        int j=m+1;
        vector<int> temp;
        while(i<=m && j<=e) {
            if(nums[i]<nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        //copy remaining elements from first array
        while(i<=m) {
            temp.push_back(nums[i++]);
        }
        //copy remaining elements from second array
        while(j<=e) {
            temp.push_back(nums[j++]);
        }
        //copy back elements from temp to original array 
        int k=0;
        for(int i=s;i<=e;i++) {
            nums[i]=temp[k++];
        }
        return;
    }
};