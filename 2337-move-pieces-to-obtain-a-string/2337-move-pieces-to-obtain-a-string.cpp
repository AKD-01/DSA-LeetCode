class Solution {
public:
    bool canChange(string start, string target) {
        stack<pair<int,int>>st;
        for(int i=0; i<target.size(); i++){
            if(target[i]=='L' || target[i]== 'R') st.push({target[i],i});
        }
        for(int i=start.size()-1; i>=0; i--){
            if(start[i]=='L'){
                if(st.empty() || st.top().first!='L' || st.top().second>i)return 0;
                st.pop();
            }
            else if(start[i]=='R'){
                if(st.empty() || st.top().first!='R' || st.top().second<i)return 0;
                st.pop();
            }
        }
        return st.empty();
    }
};