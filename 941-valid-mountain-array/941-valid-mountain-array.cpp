class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size(), i=0, j=n-1;
        while(i+1<n && arr[i]<arr[i+1]) i++;
        while(j>0 && arr[j-1]>arr[j]) j--;
        return i>0 && i==j && j<n-1;
    }
};