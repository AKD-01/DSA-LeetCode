class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(auto weight: stones){
            p.push(weight);
        }
        while(!p.empty() && p.size()>1){
            int s1 = p.top(); 
            p.pop();
            int s2 = p.top(); 
            p.pop();
            if(s1 != s2){
                p.push(s1-s2);
            }
        }
        return !p.empty() ? p.top():0; 
    }
};