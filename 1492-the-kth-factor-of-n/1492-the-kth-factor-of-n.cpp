class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> v;
        for(int i=1; i<=n; i++) {
            if(n%i==0) v.push_back(i);
        }
        int sze = v.size();
        if(k<=sze) return v[k-1];
        return -1;
    }
};