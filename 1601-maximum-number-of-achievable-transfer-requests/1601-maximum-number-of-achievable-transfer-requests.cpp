class Solution {
public:
    int bal[21] = {};
    int maximumRequests(int n, vector<vector<int>>& requests, int i = 0) {
    if (i == requests.size())
        return count(begin(bal), begin(bal) + n, 0) == n ? 0 : INT_MIN;
    --bal[requests[i][0]];
    ++bal[requests[i][1]];
    auto take = 1 + maximumRequests(n, requests, i + 1);
    ++bal[requests[i][0]];
    --bal[requests[i][1]];
    return max(take, maximumRequests(n, requests, i + 1));
}
};