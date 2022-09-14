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
    int pseudoPalindromicPaths (TreeNode* root) {
        int count=0;
        vector<int> n(10,0);
        pseudo_count(root, n, count);
        return count;
    }
    void pseudo_count(TreeNode* root, vector<int> &n, int &count) {
        if(root==NULL) return;
        n[root->val]++;
        pseudo_count(root->left,n,count);
        pseudo_count(root->right,n,count);
        if(root->left==NULL && root->right==NULL) {
            int flag=0;
            for(int i=1;i<=9;i++) {
                if(n[i]%2!=0) flag++;
            } 
            if(flag==1 || flag==0) count++; 
        }
        n[root->val]--;
    }
};