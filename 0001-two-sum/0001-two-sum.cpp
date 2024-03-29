class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Optimized approach using hashmap TC-O(n) and SC-O(n)
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0; i<n; i++) {
            int num = nums[i];
            int more = target-num;
            if(m.find(more)!=m.end()) {
                return {i,m[more]};
            }
            m[num]=i;
        }
        return {-1,-1};
    }
};

/* 
for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i]+nums[j]==target) return {i,j};
            }
        }
        return {-1,-1}; TC: O(n*n) SC: O(1)
        
unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) {
            int x=nums[i];
            int y=target-x;
            if(m.find(y)!=m.end()) return {i,m[y]};
            m[nums[i]]=i;
        }
        return {-1,-1}; TC: O(n) SC: O(n)
        
vector<pair<int,int>> v;
       int n=nums.size();
       for(int i=0;i<n;i++) v.push_back({nums[i],i});
       sort(v.begin(),v.end());
       int s=0, e=n-1;
       while(s<e) {
           int sum=v[s].first+v[e].first;
           if(sum==target) return {v[s].second,v[e].second}; 
           else if (sum>target) e--;
           else s++;
       }
        return {-1,-1}; TC: (nlogn)  SC: O(n)
        
unordered_set<int> s;
      vector<int> result;
      for(int i=0;i<nums.size();i++){
          int x=target-nums[i];
          if(s.find(x)==s.end()) {
              s.insert(nums[i]);
          }
          else {
              result.push_back(i);
              auto it=find(nums.begin(), nums.end(), x);
              int index=it-nums.begin();
              result.push_back(index);
              return result;
          }
      }
        return result; TC: omega(1) or O(logn) SC: O(n)
*/