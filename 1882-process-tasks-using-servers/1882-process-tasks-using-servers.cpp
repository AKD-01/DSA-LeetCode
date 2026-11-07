class Solution {
private:
    using PLI = pair<long long, int>;
    using PII = pair<int, int>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        priority_queue<PLI, vector<PLI>, greater<PLI>> busy;
        priority_queue<PII, vector<PII>, greater<PII>> idle;
        for (int i = 0; i < m; ++i) {
            idle.emplace(servers[i], i);
        }

        long long ts = 0;
        auto release = [&]() {
            while (!busy.empty() && busy.top().first <= ts) {
                auto&& [_, idx] = busy.top();
                idle.emplace(servers[idx], idx);
                busy.pop();
            }
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ts = max(ts, static_cast<long long>(i));
            release();
            if (idle.empty()) {
                ts = busy.top().first;
                release();
            }
            auto&& [_, idx] = idle.top();
            ans.push_back(idx);
            busy.emplace(ts + tasks[i], idx);
            idle.pop();
        }
        return ans;
    }
};