class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    if(arr.size()==0)
    {
        return {};
    }
    if(arr.size()==1)
    {
        return {1};
    }
    map<int,int> mp;
    vector<int> res(arr.begin(),arr.end());
    sort(res.begin(),res.end());
    int cnt=1;
    mp[res[0]]=cnt;
     for(int i=1;i<arr.size();i++)
     {
        if(res[i]==res[i-1])
        {
            mp[res[i]]=cnt;
        }
        else
        {
            mp[res[i]]=++cnt;
        }
     }
     for(int i=0;i<arr.size();i++)
     {
        arr[i]=mp[arr[i]];
     }
    return arr;
    }
};