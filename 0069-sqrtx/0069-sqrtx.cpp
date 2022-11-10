class Solution {
public:
    int mySqrt(int x) {
        long long int s=0;
        long long int e=x;
        float ans=0;
        //Binary Search Search Space 0...N
        while(s<=e) {
            long long int mid=(s+e)/2;
            if(mid*mid==x) {
                return mid;
            }
            else if(mid*mid<x) {
                ans=mid;
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
        return ans;
    }
};