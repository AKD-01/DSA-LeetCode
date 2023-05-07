class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> res(n, 1);
        vector<int> v;
        for(int i=0; i<n; i++) {
            int tr = upper_bound(v.begin(),v.end(),obstacles[i]) - v.begin();
            if(tr == v.size()) v.push_back(obstacles[i]);
            else v[tr] = obstacles[i];
            res[i] = tr + 1;
        }
        return res;
    }
};
