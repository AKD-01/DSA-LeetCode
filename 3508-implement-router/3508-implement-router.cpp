class Router {
public:
    map<vector<int>, int> mpp; // to track duplicates
    queue<vector<int>> queue; // to store packets in FIFO order
    unordered_map<int, vector<int>> timestamps; // for timestamps tracking
    unordered_map<int, int> st; 
    int maxSize = 0; // maxSize allowed

    Router(int memoryLimit) { 
        maxSize = memoryLimit; 
    }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        // checking for duplicate
        if (mpp.count(packet))
            return false;
        if (queue.size() == maxSize) { // remove the first element if queue is full
            vector<int> res = queue.front();
            mpp.erase(res);
            int temp = res[1];
            st[temp]++;  
            queue.pop();
        }
        queue.push(packet);
        mpp[packet]++;
        timestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if(queue.empty()) return {};
        vector<int> res = queue.front();
        queue.pop();
        mpp.erase(res);
        int temp = res[1];
        st[temp]++;
        return res;
    }

    int getCount(int destination, int startTime, int endTime) {
        if(timestamps.find(destination) == timestamps.end())
            return 0;
        auto &p = timestamps[destination];
        int temp = st[destination];
        auto right = lower_bound(p.begin() + temp, p.end(), startTime);
        auto left = upper_bound(p.begin() + temp, p.end(), endTime);
        return int(left - right);
    }
};