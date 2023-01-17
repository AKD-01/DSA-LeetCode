class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int counter_one  = 0, counter_flip = 0;
        for(auto ch : S) {
            if (ch == '1') {
                ++counter_one;
            } else {
                ++counter_flip;
            }
            counter_flip = std::min(counter_one, counter_flip);
        }
        return counter_flip;
    }
};