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
     vector<int> dfs(TreeNode* root) {
        if (!root) return { -1, -1, -1};
        vector<int> left = dfs(root->left), right = dfs(root->right);
        int res = max(max(left[1], right[0]) + 1, max(left[2], right[2]));
        return {left[1] + 1, right[0] + 1, res};
    }
    int longestZigZag(TreeNode* root) {
         return dfs(root)[2];
    }
};



   