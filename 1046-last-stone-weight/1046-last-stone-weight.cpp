class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        while(stones.size()>1) {
            int index=stones.size()-1;
            int x=stones[index];
            int y=stones[index-1];
            stones.pop_back();
            stones.pop_back();
            if(x!=y) stones.push_back(x-y);
            sort(stones.begin(),stones.end());
        }
        if(stones.size()==0) return 0;
        return stones[0];
    }
};
/*
priority_queue<int> p;
        for(auto weight: stones){
            p.push(weight);
        }
        while(p.size()>1){
            int s1 = p.top(); 
            p.pop();
            int s2 = p.top(); 
            p.pop();
            if(s1 != s2){
                p.push(s1-s2);
            }
        }
        return !p.empty() ? p.top():0; 
*/