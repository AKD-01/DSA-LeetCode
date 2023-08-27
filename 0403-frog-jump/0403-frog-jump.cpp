class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int , unordered_set<int>> hashMap;    
        hashMap[stones[0] + 1] = {1};       
        for(int i = 1 ; i < stones.size() ; ++i){      
            int position = stones[i];               
            for(auto it : hashMap[position]){           
                hashMap[position + it].insert(it);      
                hashMap[position + it + 1].insert(it + 1);
                hashMap[position + it - 1].insert(it - 1);
            }
        }
        return hashMap[stones.back()].size() != 0;    
    }
};