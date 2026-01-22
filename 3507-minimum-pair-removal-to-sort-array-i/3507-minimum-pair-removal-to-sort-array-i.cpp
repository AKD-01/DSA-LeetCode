class Solution {
public:
    int minPair(vector<int> v){
        int minSum = 1e9;
        int pos = -1;
        for(int i = 0; i < (int)v.size() - 1; i ++){
            if(v[i] + v[i + 1] < minSum){
                minSum = v[i] + v[i + 1];
                pos = i;
            }
        }
        return pos;
    }
    void mergePair(vector<int> &v, int pos){
        v[pos] += v[pos + 1];
        v.erase(v.begin() + pos + 1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!is_sorted(nums.begin(), nums.end())){
            mergePair(nums, minPair(nums));
            ops += 1;
        }
        return ops;
    }
};