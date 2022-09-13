class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int largest=0;
        int n=arr.size();
        for(int i=1;i<=n-2;) {
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1]) {
                int count=1;
                int j=i;
                while(j>=1 and  arr[j]>arr[j-1]) {
                    j--;
                    count++;
                }
                while(i<=n-2 && arr[i]>arr[i+1]) {
                    i++;
                    count++;
                }
                largest=max(largest,count);
            }
            else {
                i++;
            }
        }
        return largest;
    }
};