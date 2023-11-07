class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> temp(n);
		
        // calculate time req for each monster to reach city
        for(int i=0;i<n;i++){
            temp[i] = ceil ( (1.0*dist[i])/speed[i]);
        }
		
		// Sort according to their time
        sort(temp.begin(),temp.end());  // We are sorting because we want to kill those monsters first which take less time to reach the city
        int time=1;
		
		// Checking how many monsters we can kill
        for(int i=0;i<n;i++){
            if(time>temp[i]){  // This means current monster reached the city before we can kill it
                return i;
            }
            time++;
        }
        return n;  
    }
};