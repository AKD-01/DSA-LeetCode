class Solution {
public:
     static bool comp(vector<int> &a, vector<int> &b) {
          if (a[0]==b[0])
          {
               return a[1] > b[1];
          }
          return a[0] < b[0];
     }
     int numberOfWeakCharacters(vector<vector<int>> &properties) {
          sort(properties.begin(), properties.end(), comp); //sorting the array
          int mtn = INT_MIN;                                //max till now while moving from right
          int ans = 0;
          for (int i=properties.size()-1;i>=0;i--) {
               if(properties[i][1] < mtn) // if the second parameter is also less increase the ans
                    ans++;
               mtn=max(mtn, properties[i][1]);
          }
          return ans; 
    }
};