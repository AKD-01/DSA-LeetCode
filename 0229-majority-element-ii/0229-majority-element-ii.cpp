class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Boyer moore voting algorithm
        //since here we have to find elements having a count of more than n/3, so we can get a maximum of 2 such elements and we can get even 0 such elements as it is not given that the majority element will exist in all cases. here : TC=O(n) and SC=o(1) i.e. linear time complexity and constant space complexity. 
        int num1=-1;
        int num2=-1;
        int count1=0;
        int count2=0;
        int n=nums.size();
        for(int num: nums) {
            if(num==num1) count1++;
            else if(num==num2) count2++;
            else if(count1==0) {
                num1=num;
                count1=1;
            }
            else if(count2==0) {
                num2=num;
                count2=1;
            }
            else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        int c1=0, c2=0; 
        for(int num: nums) {
            if(num==num1) c1++;
            else if(num==num2) c2++;
        }
        if(c1>n/3) ans.push_back(num1);
        if(c2>n/3) ans.push_back(num2);
        return ans;
    }
};