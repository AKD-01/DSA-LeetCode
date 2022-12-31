class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore voting algorithm
        int candidate=0;
        int count=0;
        for(int num: nums) {
            if(count==0) candidate=num;
            if(num==candidate) count++;
            else count--;
        }
        return candidate;
    }
};