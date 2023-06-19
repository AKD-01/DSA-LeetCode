class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> altitudes;
        altitudes.push_back(0);
        for(int i=0; i<n; i++) {
            altitudes.push_back(altitudes[i]+gain[i]);
        }
        sort(altitudes.begin(),altitudes.end());
        return altitudes[n];
    }
};