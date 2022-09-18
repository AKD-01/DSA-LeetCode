class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int n=nums.size();
        unordered_set<int> s;
        for(int x: nums) {
            s.insert(x);
        }
        int largestlen=1;
        for(auto element: s) {
            int parent=element-1;
            if(s.find(parent)==s.end()) {
                int next_no=element+1;
                int cnt=1;
                while(s.find(next_no)!=s.end()) {
                    next_no++;
                    cnt++;
                }
                if(cnt>largestlen) {
                    largestlen=cnt;
                }
            }
        }
        return largestlen;
    }
};