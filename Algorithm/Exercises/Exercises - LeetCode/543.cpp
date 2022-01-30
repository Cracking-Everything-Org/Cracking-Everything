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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 1;
        int maxDiameter = 1;
        depth(root, maxDiameter);
        return maxDiameter - 1;
    }

    int depth(TreeNode* root, int& maxDiameter) {
        if (!root) return 0;
        int leftHeight = depth(root->left, maxDiameter);
        int rightHeight = depth(root->right, maxDiameter);
        // global
        maxDiameter = max(maxDiameter, leftHeight + rightHeight + 1);
        // local
        return max(leftHeight, rightHeight) + 1;
    }
};


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findDiameter(root, diameter);
        return diameter;
    }
    
    int findDiameter(TreeNode* root, int& diameter) {
        if (!root) return 0;
        int left = findDiameter(root->left, diameter);
        int right = findDiameter(root->right, diameter);
        diameter = max(left + right, diameter);
        return max(left, right) + 1;
    }
};
