class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>> pq;
        int count = 0, units=0;
        for(auto it: boxTypes){
            pq.push({it[1],it[0]});
        }
        while(!pq.empty() && count<truckSize) {
            if(count+pq.top().second<truckSize) {
                count+=pq.top().second;
                units+=pq.top().second*pq.top().first;
                pq.pop();
            }
            else {
                int quantity = truckSize - count; 
                count+=quantity;
                units+=quantity*pq.top().first;
                pq.pop();
            }
        }
       return units; 
    }
};