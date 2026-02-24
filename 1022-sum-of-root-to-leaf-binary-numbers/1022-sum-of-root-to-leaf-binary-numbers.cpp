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
    int sumRootToLeaf(TreeNode* root) {
        return DFS(root, 0);
    }
    int DFS(TreeNode* rt, int x) {
        if (rt == nullptr) return 0;
        x = x * 2 + rt->val;
        if (rt->left == rt->right) return x;
        return DFS(rt->left, x) + DFS(rt->right, x);
    }
};