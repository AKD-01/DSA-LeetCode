class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1=INT_MAX, num2=INT_MAX;
        for(int num : nums) {
            if(num<=num1) num1=num;
            else if(num<=num2) num2=num;
            else return true;
        }
        return false;
    }
};