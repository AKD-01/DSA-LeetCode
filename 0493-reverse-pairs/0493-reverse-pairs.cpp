class Solution {
public:
    int merge(int s, int mid, int e, vector<int> &nums) {
        int j=mid+1;
        int count=0;
        for(int i=s; i<=mid; i++) {
            while(j<=e and nums[i]>2ll*nums[j]) {
                j++;
            }
            count+=j-(mid+1);
        }
        
        int left=s;
        int right=mid+1;
        vector<int> temp;
        while(left<=mid and right<=e) {
            if(nums[left]>=nums[right]) temp.push_back(nums[right++]);
            else temp.push_back(nums[left++]);
        }
        while(left<=mid) {
            temp.push_back(nums[left++]);
        }
        while(right<=e) {
            temp.push_back(nums[right++]);
        }
        
        int k=0;
        for(int i=s; i<=e; i++) {
            nums[i]=temp[k++];
        }
        return count;
    }
    int reversepaircount(int s, int e, vector<int> &nums) {
        if(s>=e) return 0;
        int mid=(s+e)/2;
        int inv=reversepaircount(s, mid, nums);
        inv+=reversepaircount(mid+1,e,nums);
        inv+=merge(s,mid,e,nums);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        return reversepaircount(s, e, nums);
    }
};