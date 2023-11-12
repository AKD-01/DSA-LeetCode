class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
                unordered_map<int,vector<int>>path;
        int n  = routes.size();
        for(int i=0;i<n;i++){
            for(auto it:routes[i]) path[it].push_back(i);
        }
        unordered_map<int,bool>BusUsed,stationUsed;
        queue<pair<int,int>>q;
        //    start     bus_counts
        q.push({source , 0});
        while(q.size()){
            int busStop = q.front().first;
            int busCnt = q.front().second;
            q.pop();
            if(busStop == target) return busCnt;

            for(auto buses : path[busStop]){
                if(!BusUsed[buses]){
                    for(auto otherStations : routes[buses]){
                        if(!stationUsed[otherStations]){
                            stationUsed[otherStations] = true;
                            q.push({otherStations , busCnt+1});
                        }
                    }
                BusUsed[buses] = true;
                }
            }
        }
        return -1;
    }
};