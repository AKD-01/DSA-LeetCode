class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int l = 0,r = 0;
        int n = nums.size();
        
        multiset<int> st;
        while(l<n){
            
            while(r<n){
                if(st.size()==0){
                    st.insert(nums[r]);
                    r++;
                }
                else{
                    int mn = *st.begin();    
                    int mx = *st.rbegin();
                
                    mn = min(mn,nums[r]);
                    mx = max(mx,nums[r]);
                    if(mx-mn>2)break;
                    st.insert(nums[r]);
                    r++;
                }
            }
          
            long long len = r-l;
            ans+=len;
            st.erase(st.find(nums[l]));
            l++;
        }
        return ans;  
    }
};