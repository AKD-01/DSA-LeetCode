class Solution {
public:
    bool canplaceballs(int m, int n, vector<int> &position, int sep) {
        int balls=1;
        int location=position[0];
        for(int i=1;i<n;i++) {
            int current_l=position[i];
            if(current_l-location>=sep) {
                balls++;
                location=current_l;
                if(balls==m) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int s=0;
        int e=position[n-1]-position[0];
        int ans=-1;
        while(s<=e) {
            int mid=(s+e)/2;
            bool canplace = canplaceballs(m,n,position,mid);
            if(canplace) {
                ans=mid;
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
        return ans;
    }
};