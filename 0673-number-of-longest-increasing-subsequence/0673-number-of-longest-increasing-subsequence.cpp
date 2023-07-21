class Solution {
public:
    
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> lis(n,1);  // stores length of longest sequence till i-th position
        vector<int> count(n,1);  // stores count of longest sequence of length lis[i]
        int maxLen = 1;  // maximum length of lis
		
		// O(N^2) DP Solution
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(lis[j] + 1 > lis[i]){ // strictly increasing
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    } 
					 // this means there are more subsequences of same length ending at length lis[i]
					else if(lis[j]+1 == lis[i]){ 
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen,lis[i]);
        }
        
        int numOfLIS = 0;
        // count all the subseq of length maxLen
        for(int i=0;i<n;i++){
            if(lis[i]==maxLen)
                numOfLIS += count[i];
        }
            
        return numOfLIS;
    }
};