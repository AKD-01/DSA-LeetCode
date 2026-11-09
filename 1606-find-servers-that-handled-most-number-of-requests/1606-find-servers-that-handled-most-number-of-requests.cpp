class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        vector<int> res;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<int> servers;

        for(int i = 0; i < k; i++) {
            servers.insert(i);
        }

        vector<int> reqCnt(k, 0);

        int n = arrival.size();
        int mxReq = 0;
        for(int i = 0; i < n; i++) {

            while(!pq.empty() && arrival[i] >= pq.top().first) {
                servers.insert(pq.top().second);
                pq.pop();
            }

            if(servers.size() == 0) continue;

            int reqServer = i % k;
            auto itrServer = servers.lower_bound(reqServer);

            auto availServer = -1;
            if(itrServer == servers.end()) {
                availServer = *servers.begin();
            } else {
                availServer = *itrServer;
            }

            servers.erase(availServer);

            pq.push({arrival[i] + load[i], availServer});
            reqCnt[availServer]++;

            mxReq = max(mxReq, reqCnt[availServer]);
        }

        for(int i = 0; i < k; i++) {

            if(reqCnt[i] == mxReq) {
                res.push_back(i);
            }
        }

        return res;

    }
};