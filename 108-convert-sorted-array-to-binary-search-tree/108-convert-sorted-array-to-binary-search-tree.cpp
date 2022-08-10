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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return  binary_Search(nums, 0, nums.size()-1);
    }
    TreeNode*  binary_Search(vector<int> &nums, int low, int high) {
        if(low>high) return NULL;
        int mid = low + (high -low)/2;
        TreeNode* root = new TreeNode();
        root->val = nums[mid];
        root->left = binary_Search(nums, low, mid -1);
        root->right = binary_Search(nums, mid+1, high);
        return root;
    }
};