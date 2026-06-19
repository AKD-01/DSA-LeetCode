class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int highestPoint = currentAltitude;
        
        for (int altitudeGain : gain) {
            currentAltitude += altitudeGain;
            highestPoint = max(highestPoint, currentAltitude);
        }
        
        return highestPoint;
    }
};