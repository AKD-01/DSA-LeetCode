class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int normal=0, win=0, maxwin=0;
        for(int i=0; i<customers.size(); i++){
            normal+=(!grumpy[i])*customers[i];
            win+=customers[i]*grumpy[i];
            if(i>=X) win-=customers[i-X]*grumpy[i-X]; 
            maxwin=max(maxwin, win);
        }
        return normal+maxwin;
    }
};