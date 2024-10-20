class Solution {
public:
    bool parseBoolExpr(string s) {
        int n = s.length();
        stack<pair<char,int>>st;
        vector<pair<int,int>>oc;
        for(int i=0;i<n;i++){
            if(s[i] == '(')st.push({'(',i});
            else if(s[i] == ')'){
                int ind = st.top().second;
                st.pop();
                oc.push_back({ind,i});
            }
        }
        unordered_map<int,pair<int,char>>mp;
        for(auto i : oc){
            int si = i.first , ei = i.second;
            int ind = si-1,ctf = 0,ctt = 0;
            for(int k=si+1;k<ei;k++){
                if(mp.find(k) != mp.end()){
                    if(mp[k].second == 'f')ctf++;
                    else ctt++;
                    k = mp[k].first;
                }
                else{
                    if(s[k] == 'f')ctf++;
                    else if(s[k] == 't')ctt++;
                }
            }
            if(s[ind] == '|'){
                if(ctt > 0)mp[ind] = {ei,'t'};
                else mp[ind] = {ei,'f'};
            }
            else if(s[ind] == '!'){
                if(ctt == 1)mp[ind] = {ei,'f'};
                else mp[ind] = {ei,'t'};
            }
            else{
                if(ctf > 0)mp[ind] = {ei,'f'};
                else mp[ind] = {ei,'t'};
            }
        }
        if(mp[0].second == 'f')return false;
        else return true;  
    }
};