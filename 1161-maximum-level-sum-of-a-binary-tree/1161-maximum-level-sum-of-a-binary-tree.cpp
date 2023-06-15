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
    int maxLevelSum(TreeNode* r) {
        vector<TreeNode*> q{r};
        int lvl = 0, msum_lvl = 0, msum = INT_MIN;
        while (!q.empty()) {
            vector<TreeNode*> q1;
            int sum = 0;
            ++lvl;
            for (auto n : q) {
                sum += n->val;
                if (n->left != nullptr) 
                    q1.push_back(n->left);
                if (n->right != nullptr) 
                    q1.push_back(n->right);
            }
            msum_lvl = sum > msum ? lvl : msum_lvl;
            msum = max(sum, msum);
            swap(q, q1);
        }
        return msum_lvl;
    }
};