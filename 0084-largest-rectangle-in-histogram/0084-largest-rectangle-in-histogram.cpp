class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          int ret = 0;
        for (auto it = heights.begin(); it != heights.end(); ++it) {
            int prev = it != heights.begin() ? *(it - 1) : 0;
            int target_height = *it;
            auto end = it + 1;
            while (target_height > prev) {
                while (end != heights.end() && *end >= target_height) {
                    ++end;
                }
                ret = max(ret, target_height * (int)(end - it));
                if (end == heights.end()) {
                    break;
                }
                target_height = *end;
                ++end;
            }
        }
        return ret;
    }
};