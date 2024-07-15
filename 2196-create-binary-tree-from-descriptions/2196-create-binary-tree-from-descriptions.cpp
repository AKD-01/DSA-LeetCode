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
    TreeNode* createBinaryTree(vector<vector<int>>& desp) {
        unordered_map<int, TreeNode*> m;
        unordered_map<int, bool> root;
        int r;
        
        for(auto d : desp) root[d[0]] = root[d[1]] = true;

        for(auto d : desp) {
            root[d[1]] = false;
            TreeNode *par, *node;
            m.count(d[0]) ? par = m[d[0]] : par = new TreeNode(d[0]), m[d[0]]=par;
            m.count(d[1]) ? node = m[d[1]] : node = new TreeNode(d[1]), m[d[1]]=node;
            d[2] ? par->left = node : par->right = node;  
        }
        
        for(auto x : root)
            if(x.second)
                r = x.first;
        
        return m[r];
    }
};