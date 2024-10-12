class Solution {
public:
    int minGroups(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(arr[0][1]);
        for(int i = 1; i < n; i++)
        {
            if(arr[i][0] > pq.top())
            {
                pq.pop();
            }
            
            pq.push(arr[i][1]);
        }
        
        return pq.size();
    }
};