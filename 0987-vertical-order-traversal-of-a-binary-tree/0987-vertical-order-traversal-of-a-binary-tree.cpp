/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       vector<vector<int>> ans;
       if(root==NULL) return ans;
       queue<pair<int,pair<int,TreeNode*>>> q;
       map<int, map<int, multiset<int>>> m;
       q.push({0,{0,root}});
       while(!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode * node = it.second.second;
        int v= it.first, l = it.second.first;
        m[v][l].insert(node->val);
        if(node->left) q.push({v-1,{l+1, node->left}});
        if(node->right) q.push({v+1,{l+1, node->right}});
       }
       for(auto p: m) {
        vector<int> col; 
        for(auto q: p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
       }
       return ans;
    }
};