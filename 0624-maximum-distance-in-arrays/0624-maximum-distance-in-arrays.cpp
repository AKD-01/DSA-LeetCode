class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
       int n = arrays.size();
        int min_num = arrays[0].front();
        int max_num = arrays[0].back();
        int max_dis = INT_MIN;

        for(int i=1; i<n; i++)
        {
            max_dis = max({max_dis, abs(arrays[i].back() - min_num), abs(arrays[i].front() - max_num)});
            min_num = min(min_num, arrays[i].front());
            max_num = max(max_num, arrays[i].back());
        }

        return max_dis; 
    }
};