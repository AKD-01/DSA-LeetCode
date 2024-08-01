class Solution {
public:
    int countSeniors(vector<string>& details) {
       int count = 0;
        for(string detail: details){
            char one = detail[11] - '0';
            char two = detail[12] - '0';
            if((one >= 7) || (one >= 6 && two > 0)) count++;
        }
        return count; 
    }
};