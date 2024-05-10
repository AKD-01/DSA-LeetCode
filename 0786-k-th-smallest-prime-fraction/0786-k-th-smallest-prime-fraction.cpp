class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
      priority_queue<pair<double, pair<int,int>>>pq;
        for(int i = 0; i < A.size(); i++)
            pq.push({-1.0*A[i]/A.back(), {i,A.size()-1}});
        while(--K > 0)
        {
            pair<int,int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0*A[cur.first]/A[cur.second], {cur.first, cur.second}});
        }
        return {A[pq.top().second.first], A[pq.top().second.second]};  
    }
};