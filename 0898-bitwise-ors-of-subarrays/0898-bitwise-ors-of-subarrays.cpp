class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
       unordered_set<int> uniqueOrValues;  
       int currentOr = 0;
      
        for (int i = 0; i < arr.size(); ++i) {
            currentOr |= arr[i];            
            int subarrayOr = 0;             
            for (int j = i; j >= 0; --j) {
                subarrayOr |= arr[j];       
                uniqueOrValues.insert(subarrayOr);
                if (subarrayOr == currentOr) break;
            }
        }
        return uniqueOrValues.size(); 
    }
};