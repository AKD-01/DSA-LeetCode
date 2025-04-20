class Solution {
public:
    int numRabbits(vector<int>& answers) {
      unordered_map<int, int> freq;
        for (int ans : answers) {
            freq[ans]++;
        }
        
        int res = 0;
        for (auto& [k, v] : freq) {
            int groupSize = k + 1;
            int groups = (v + groupSize - 1) / groupSize; 
            res += groups * groupSize;
        }
        
        return res;  
    }
};