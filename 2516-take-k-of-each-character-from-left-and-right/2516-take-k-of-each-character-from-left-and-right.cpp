class Solution {
public:
    int solve(string s,vector<int>&vec,int k , int j){
    int ans = s.size() - j;
    for (int i = 0; i < s.size(); i += 1) {
        vec[s[i] - 'a'] += 1;
        while (j < s.size()) {
            vec[s[j] - 'a'] -= 1;
            if (*min_element(vec.begin(), vec.end()) >= k) {
                j += 1;
            } else {
                vec[s[j] - 'a'] += 1;
                break;
            }
        }
        int check = i + 1 + s.size() - j;
        ans = min(ans, check);
    }
    return ans;
   }
    int takeCharacters(string s, int k) {
    vector<int> vec(3);
    int j = s.size();
    while (j and *min_element(vec.begin(),vec.end()) < k) {
        j -= 1;
        vec[s[j] - 'a'] += 1;
    }
    if (*min_element(vec.begin(), vec.end()) < k) return -1;
     return solve(s,vec,k,j);
    }
    };