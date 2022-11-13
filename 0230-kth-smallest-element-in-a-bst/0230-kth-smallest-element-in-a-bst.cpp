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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vSmallest;
        Smallestkth(root,k,vSmallest);
        return vSmallest[k-1];
    }
    void Smallestkth(TreeNode* root, int k, vector<int> &vSmallest) {
        if(root->left) Smallestkth(root->left,k,vSmallest);
        vSmallest.push_back(root->val);
        if(root->right) Smallestkth(root->right,k,vSmallest);
    }
};

