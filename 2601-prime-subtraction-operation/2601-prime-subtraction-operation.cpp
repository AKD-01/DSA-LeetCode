class Solution {
public:
    bool prime(int n){
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i == 0)return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> p;
        int i,n=nums.size(),j,x;
        for(i = 2; i <= 1000; i++){
            if(prime(i)){
                // cout<<i<<" ";
                p.push_back(i);
            }
        }
        // cout<<endl;
        for(i = 0; i < n; i++){
            if(i==0){
                j = p.size();
                while(j--){
                    if(p[j]<nums[i]){
                        break;
                    }
                }
                if(j==-1)continue;
                nums[i] -= p[j];
            }else{
                j = p.size(),x=0;
                while(j--){
                    if(nums[i]-p[j] > nums[i-1]&&p[j]<nums[i]){
                        x = p[j];
                        break;
                    }
                }
                if(j>=0){
                    nums[i] -= x;
                }
            }
        }
        //<!-- for(auto &i: nums)cout<<i<<" "; -->
        for(i = 1; i < n; i++){
            if(nums[i-1]>=nums[i]) return false;

        }
        return true;
    }
};