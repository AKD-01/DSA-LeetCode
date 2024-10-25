class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;

        sort(folder.begin(),folder.end());

        stack<string>stk;
        stk.push(folder[0]);
        for(int i = 1; i<folder.size();i++)
        {
            string temp = stk.top() + '/';
            if(folder[i].compare(0,temp.size(),temp) == 0)
                continue;
            else
                stk.push(folder[i]);
        }
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
 
    }
};