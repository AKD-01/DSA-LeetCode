class Solution {
public:
    int n;
    unordered_set<string> numsSet;
    
    string generate(string curr) {
        if (curr.size() == n) {
            if (numsSet.find(curr) == numsSet.end()) {
                return curr;
            }
            
            return "";
        }
        
        string addZero = generate(curr + "0");
        if (addZero.size() > 0) {
            return addZero;
        }
        
        return generate(curr + "1");
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for (string s : nums) {
            numsSet.insert(s);
        }
        
        return generate("");
    }
};