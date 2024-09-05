class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> roll;
        int allSum= 0;

        for(int i= 0; i < rolls.size(); i++)
        {
            allSum += rolls[i];
        }

        int m= rolls.size();
        int all= mean*(m+n) - allSum;

        if( (n*6) < all )
        return roll;
       
        int i= n-1, j= 0;
        while( i-- )
        {
            int num= all/ n;
            if( num < 1 )
            {
                return roll;
            }
            
            roll.push_back(num);
            all= all- num;
            n--;
            
        }

        roll.push_back(all);

        return roll; 
    }
};