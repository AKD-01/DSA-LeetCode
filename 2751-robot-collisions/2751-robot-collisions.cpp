class Solution {
public:
     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& h, string directions) {
        int n = positions.size();
        vector<int> ind(n), stack, res;
        for (int i = 0; i < n; i++)
            ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        for (int i : ind) {
            if (directions[i] == 'R') {
                stack.push_back(i);
                continue;
            }
            while (!stack.empty() && h[i] > 0) {
                if (h[stack.back()] < h[i]) {
                    h[stack.back()] = 0, stack.pop_back();
                    h[i] -= 1;
                } else if (h[stack.back()] > h[i]) {
                    h[stack.back()] -= 1;
                    h[i] = 0;
                } else {
                    h[stack.back()] = 0, stack.pop_back();
                    h[i] = 0;
                }
            }
        }
        for (int v : h) {
            if (v > 0) {
                res.push_back(v);
            }
        }
        return res;
    }
};