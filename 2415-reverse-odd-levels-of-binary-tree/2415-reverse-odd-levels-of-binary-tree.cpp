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
    TreeNode* reverseOddLevels(TreeNode* root) {
       if (root == NULL) {
            return root;
        }
        queue<TreeNode*> q;
        vector<int> v;
        int level = 0, size;
        q.push(root);
        while (!q.empty()) {
            size = q.size();
            vector<int> temp;
            while (size--) {
                TreeNode *node = q.front();
                q.pop();
                if (level & 1) {
                    node->val = v[size];
                }
                if (node->left) {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if (node->right) {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            v = temp;
            level++;
        }
        return root;  
    }
};