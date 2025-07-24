class Solution {
public:
    int calc(int part1, int part2, int part3) {
        return max(part1, max(part2, part3)) - min(part1, min(part2, part3));
    }

    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size();
        vector<vector<int>> e(n);
        for (auto &v : edges) {
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }

        int sum = 0;
        for (int x : nums) {
            sum ^= x;
        }

        int res = INT_MAX;
        function<int(int, int, int, int)> dfs2 = [&](int x, int f, int oth,
                                                     int anc) {
            int son = nums[x];
            for (auto &y : e[x]) {
                if (y == f) {
                    continue;
                }
                son ^= dfs2(y, x, oth, anc);
            }
            if (f == anc) {
                return son;
            }
            res = min(res, calc(oth, son, sum ^ oth ^ son));
            return son;
        };

        function<int(int, int)> dfs = [&](int x, int f) {
            int son = nums[x];
            for (auto &y : e[x]) {
                if (y == f) {
                    continue;
                }
                son ^= dfs(y, x);
            }

            for (auto &y : e[x]) {
                if (y == f) {
                    dfs2(y, x, son, x);
                }
            }
            return son;
        };

        dfs(0, -1);
        return res;
    }
};