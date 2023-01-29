class Solution {
public:
    int largestRectangleArea(vector<int>& vec) {
          vector<int> a(vec.size());
        stack<pair<int, int>> s;
         
        // nearest smallest to left;
        for(int i=0;i<vec.size();i++) {
            while(s.size() && s.top().first >= vec[i]) s.pop();
            a[i] = s.empty() ? -1 : s.top().second;
            s.push({vec[i], i});
        }
        while(s.size()) s.pop();
        for(auto i : a) cout<<i<<" ";

        int maxrec = 0;
        // nearest smallest to right; 
        for(int i=vec.size()-1;i>=0;i--) {
            while(s.size() && s.top().first >= vec[i]) s.pop();
            int j = s.empty() ? vec.size() : s.top().second;
            maxrec = max((j - a[i] - 1) * vec[i], maxrec);
            s.push({vec[i], i});
        }
        return maxrec;
    }
};