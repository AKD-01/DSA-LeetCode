/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s=1, e=n;
        int myguess;
        while(s<=e) {
            myguess=s+(e-s)/2;
            int res=guess(myguess);
            if(res==0) {
                return myguess;
            }
            else if(res==-1) {
                e=myguess-1;
            }
            else {
                s=myguess+1;
            }
        }
        return myguess;
    }
};