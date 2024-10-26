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
    int level[100001] = {}, depth[100001] = {};
    int d1[100001] = {}, d2[100001] = {};
    int traverse(TreeNode* n, int l = 0) {
    if (n == nullptr) return 0;
    level[n->val] = l;
    depth[n->val] = 1 + max(traverse(n->left, l + 1), traverse(n->right, l + 1));   
    if (d1[l] < depth[n->val]) {
        d2[l] = d1[l];
        d1[l] = depth[n->val];
    } 
    else if (d2[l] < depth[n->val])
        d2[l] = depth[n->val];
    return depth[n->val];
    };
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    traverse(root, 0);
    transform(begin(queries), end(queries), begin(queries), [&](int q){
        int l = level[q];
        return l + (d1[l] == depth[q] ? d2[l] : d1[l]) - 1;
    });
    return queries;
   }
};