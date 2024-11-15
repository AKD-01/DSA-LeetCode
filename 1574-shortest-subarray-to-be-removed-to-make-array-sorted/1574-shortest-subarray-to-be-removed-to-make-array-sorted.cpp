class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
       int size = arr.size();
        int r;
        
        for (r = size - 1; r >= 1; r--) if (arr[r - 1] > arr[r]) break;
        
        int ans = r;
        for (int i = 0; i < size - 1 && i < r; i++) {
            if (r == size || arr[i] <= arr[r]) ans = min(ans, r - i - 1);
            else r++;
            
            if (arr[i + 1] < arr[i]) break;
        }
        
        return ans;
    }
};