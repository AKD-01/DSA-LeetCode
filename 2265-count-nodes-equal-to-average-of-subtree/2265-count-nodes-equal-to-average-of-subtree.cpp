class Solution {
public:
    int count = 0;
    
    pair<int, int> postOrder(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        
        pair<int, int> left = postOrder(root->left);
        pair<int, int> right = postOrder(root->right);
        
        int nodeSum = left.first + right.first + root->val;
        int nodeCount = left.second + right.second + 1;

        if (root->val == nodeSum / (nodeCount)) {
            count++;
        }
        
        return {nodeSum, nodeCount};
    }
    
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return count;
    }
};