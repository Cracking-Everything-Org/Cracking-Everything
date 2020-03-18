/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return findSum(root, 0);
    }

    int findSum(TreeNode* root, int currentSum) {
        if (!root) return 0;
        currentSum = currentSum * 10 + root->val;
        if (!root->left && !root->right) {
            return currentSum;
        }
        return findSum(root->left, currentSum) + findSum(root->right, currentSum);
    }
};
