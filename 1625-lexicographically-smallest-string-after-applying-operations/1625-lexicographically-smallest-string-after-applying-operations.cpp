class Solution {
public:
    string findLexSmallestString(string str, int a, int b) {
        unordered_set<string> seen; // to keep track of seen strings
        queue<string> q;
        q.push(str);
        
        string lex_smallest_string = str;
        
        while(q.empty() == false) //simple-bfs
        {
            string s = q.front();
            q.pop();

            lex_smallest_string = min(lex_smallest_string , s);

            // Pushing all those childs which are not seen yet!!!
            // 1st child is formed by applying operation 1 on string
            // 2nd child is formed by applying operation 2 on string

            string first_child = apply_operation_1(s , a);
            if(seen.find(first_child) == seen.end())
                q.push(first_child) , seen.insert(first_child);

            string second_child = apply_operation_2(s , b);
            if(seen.find(second_child) == seen.end())
                q.push(second_child) , seen.insert(second_child);
        }
        return lex_smallest_string;
    }
    
    string apply_operation_1(string s , int a)
    {
    // Operation 1 : states that increasing all odd indices of string a times!!!!
        for(int i = 1 ; i < s.size() ; i += 2)
            s[i] = (s[i] - '0' + a) % 10 + '0';
        return s;
    }
    
    string apply_operation_2(string s , int b)
    {
    // Operation 2 : states that we have to rotate string to right b times!!!!!
        string res(s.size() , ' ');
        for(int i = 0 ; i < s.size() ; ++i)
            res[(i + b) % s.size()] = s[i];
        return res;

    }
};