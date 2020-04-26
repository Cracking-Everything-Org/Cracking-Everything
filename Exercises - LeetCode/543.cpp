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
        if(!root) return 0;
        int maxDia = 1;
        diameter(root, maxDia);
        return maxDia - 1;
    }

    int diameter(TreeNode* root, int& maxDia) {
        if (!root) return 0;
        int leftDiameter = diameter(root->left, maxDia);
        int rightDiameter = diameter(root->right, maxDia);
        maxDia = max(maxDia, leftDiameter + rightDiameter + 1);
        return max(leftDiameter, rightDiameter) + 1;
    }
};
