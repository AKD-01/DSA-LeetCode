class Solution {
public:
    typedef long long ll;
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        ll sum=0;
        for(int x:nums)
        sum+=x;
        if(sum%p==0)
        return 0;
        ll s=0;
        ll mini=n;
        map<ll,ll> m;
        m[0]=-1;
        sum%=p;
        for(int i=0;i<n;i++)
        {
           s+=nums[i];
            s=s%p;
           if(m.count((s-sum+p)%p))
            mini=min(mini,i-m[(s-sum+p)%p]);
            m[s%p]=i;
        }
        cout<<mini<<endl;
        return (mini<n)?mini:-1;
    }
};