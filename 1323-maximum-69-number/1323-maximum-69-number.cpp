class Solution {
public:
    int maximum69Number (int num) {
    //go through each digit of the number from least significant
    //keep track of the most significant 6 digit seen
    int p = 1;
    int n = num;
    int maxp = 0;
    while(num>0) {
		int digit = (num % 10);
        if(digit==6) {
			maxp = p;
		}
        p*=10;
        num/=10;
	}
    //change this '6' to '9' by adding 3*max6bit position
    n+=(maxp*3);
    return n;
    }
};