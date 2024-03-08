class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0}, maxF=0, f=0;
        for (int x: nums){
            freq[x]++;
            f+=(freq[x]==maxF);
            if (freq[x]> maxF) f=1, maxF=freq[x];
        }
        return f*maxF;
    }
};