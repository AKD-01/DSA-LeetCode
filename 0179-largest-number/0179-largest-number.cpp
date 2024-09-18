class Solution {
public:
    bool static cmp(string a, string b) {
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
       vector<string> v;
       for(int i=0; i<nums.size(); i++) {
           v.push_back(to_string(nums[i]));
       }
        sort(v.begin(), v.end(), cmp);
        string ans;
        for(int i=0; i<v.size(); i++) {
            ans+=v[i];
        }
        return ans[0]=='0'? "0" : ans;
    }
};