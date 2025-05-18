class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int colorTheGrid(int m, int n) {
        unordered_map<int, vector<int>> valid;
        int mask_end = pow(3, m);
        for (int mask = 0; mask < mask_end; ++mask) {
            vector<int> color;
            int mm = mask;
            for (int i = 0; i < m; ++i) {
                color.push_back(mm % 3);
                mm /= 3;
            }
            bool check = true;
            for (int i = 0; i < m - 1; ++i) {
                if (color[i] == color[i + 1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                valid[mask] = move(color);
            }
        }
        unordered_map<int, vector<int>> adjacent;
        for (const auto& [mask1, color1] : valid) {
            for (const auto& [mask2, color2] : valid) {
                bool check = true;
                for (int i = 0; i < m; ++i) {
                    if (color1[i] == color2[i]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    adjacent[mask1].push_back(mask2);
                }
            }
        }

        vector<int> f(mask_end);
        for (const auto& [mask, _] : valid) {
            f[mask] = 1;
        }
        for (int i = 1; i < n; ++i) {
            vector<int> g(mask_end);
            for (const auto& [mask2, _] : valid) {
                for (int mask1 : adjacent[mask2]) {
                    g[mask2] += f[mask1];
                    if (g[mask2] >= mod) {
                        g[mask2] -= mod;
                    }
                }
            }
            f = move(g);
        }

        int ans = 0;
        for (int num : f) {
            ans += num;
            if (ans >= mod) {
                ans -= mod;
            }
        }
        return ans;
    }
};