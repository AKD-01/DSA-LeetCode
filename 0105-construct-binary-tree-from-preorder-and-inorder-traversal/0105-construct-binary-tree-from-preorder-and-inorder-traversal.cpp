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
    int preIdx;
    unordered_map<int,int> inIndexOf;   // inorder index of a number

    TreeNode* helper (vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left <= right) {
            int inIdx = inIndexOf[preorder[preIdx]];
            TreeNode *t = new TreeNode(inorder[inIdx]);
            preIdx ++;
            
            t->left = helper(preorder, inorder, left, inIdx-1);
            t->right = helper(preorder, inorder, inIdx+1, right);
            return t;
        }
        else return NULL;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIdx = 0;
        inIndexOf.clear();

        int n = preorder.size();
        for (int i=0 ; i<n ; i++)
            inIndexOf[inorder[i]] = i;
        return helper(preorder, inorder, 0, n-1);
    }
};