class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++) {
            vector<int> v;
            for(int j=l[i]; j<=r[i]; j++) {
                v.push_back(nums[j]);
            }
            sort(v.begin(), v.end());
            int fd = v[1] - v[0];
            bool fl = true;
            for(int j=2; j<v.size(); j++) {
                if(v[j] - v[j-1] != fd) {
                    fl = false;
                    break;
                }
            }
            ans.push_back(fl);
        }
        return ans;
    }
};