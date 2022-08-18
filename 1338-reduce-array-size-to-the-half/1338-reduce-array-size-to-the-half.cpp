class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        priority_queue<int> q;
        int result = 0, removed = 0;
        for (auto a : arr) m[a]++;
        for (auto c : m) q.push(c.second);
        while (removed < arr.size() / 2) {
            removed += q.top();
            q.pop();
            result++;
        }
        return result;
    }
};