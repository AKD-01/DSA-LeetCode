class Solution {

public:
    int maxValue(vector<vector<int>>& events, int k) {

        int n = events.size();
        int ans = 0;

        //sort by start time.
        sort(events.begin(),events.end());

        //dp[i][j] : profit , from event i to end, max attend j event //dp[n][] is sentinel
        // vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        //space optimized
        vector<int> dp(n+1,0) , dp_pre(n+1,0); //dp[n] is sentinel

        //do it once and only once , to find each event next unconflict.
        vector<int> next_event(n,n); //let default point to sentinel

        auto cmp = [](const vector<int> &cur_event,const vector<int> &event){ 
            return cur_event[1] < event[0];
        };

        for(int i=n-2;i>=0;i--) next_event[i] = 
        distance(events.begin(),upper_bound(events.begin()+i,events.end(),events[i],cmp));

        //update col by col.
        for(int t = 1;t<=k;t++){
            for(int i=n-1;i>=0;i--){
                dp[i] = max(dp[i+1],events[i][2]+dp_pre[next_event[i]]);
                ans = max(ans,dp[i]);
            }
            dp.swap(dp_pre);
        }
        
        return ans;
    }
};