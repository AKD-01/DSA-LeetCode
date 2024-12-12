class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
      priority_queue<int> pq;
        for(auto &i: gifts){
            pq.push(i);
        }
        long long int ans = 0;
        int x;
        while(k--){
            x = pq.top();
            pq.pop();
            pq.push(sqrt(x));
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;  
    }
};