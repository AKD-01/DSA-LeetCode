class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long all = accumulate(chalk.begin(), chalk.end(), 0LL);

        k %= all;
        int n = chalk.size();
        for(int i = 0; i < n; i++) {
            if(k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        return n-1;  
    }
};