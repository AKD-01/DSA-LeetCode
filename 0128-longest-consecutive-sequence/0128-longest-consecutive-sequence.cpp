class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num: nums) {
            s.insert(num);
        }
        int longest_streak=0;
        for(int num: nums) {
            if(!s.count(num-1)) {
                int currentnum=num;
                int currentstreak=1;
                while(s.count(currentnum+1)){
                    currentnum+=1;
                    currentstreak+=1;
                }
                longest_streak=max(longest_streak,currentstreak);
            }  
        }
        return longest_streak;
    }
};