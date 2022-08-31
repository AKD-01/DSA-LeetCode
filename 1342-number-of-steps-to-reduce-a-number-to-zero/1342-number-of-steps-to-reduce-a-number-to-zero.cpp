class Solution {
public:
    int numberOfSteps(int num) {
       int count=0;
        while(num){
            if(num%2){ // odd
                --num;
            }
            else{ // even
                num>>=1; // num=num/2
            }
            ++count;
        }
        return count;
    } 
};