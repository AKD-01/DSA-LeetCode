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
    string answer = "~";
    public:     
    void recure(TreeNode* root,string s){
        if (!root) return;
        if (!root->left && !root->right){
            answer = min(answer,char(root->val+'a')+s);
        }
        recure(root->left,char(root->val+'a')+s);
        recure(root->right,char(root->val+'a')+s);
    }
    string smallestFromLeaf(TreeNode* root) {
        recure(root,"");
        return answer;
    }
};