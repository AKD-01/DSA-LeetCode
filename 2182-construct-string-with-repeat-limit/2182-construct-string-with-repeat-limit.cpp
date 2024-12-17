class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
       int n(size(s));
        vector <int> m(26, 0);
        for (auto ch : s)   m[ch-'a']++;
        
        priority_queue <pair<char, int>> pq;
        for (int i=0; i<26; i++)
            if (m[i])   
                pq.push({i+'a', m[i]});
        
        string res;
        
        while (!pq.empty()) {
		
            auto top = pq.top(); pq.pop();  
            here :
            int lim = min(top.second, repeatLimit); 
            top.second -= lim;
			
            while (lim--)   res.push_back(top.first);
            if (top.second > 0) {
                if (pq.empty()) return res; 
                auto next = pq.top(); pq.pop(); 
                res.push_back(next.first);
                next.second -= 1;
                if (next.second)    pq.push(next);
                goto here;
            }
        }
        
        return res; 
    }
};