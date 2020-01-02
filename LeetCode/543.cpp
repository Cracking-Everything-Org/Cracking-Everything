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
    int diameter(TreeNode *root, int &d){
        if(!root) return 0;
        int l = diameter(root->left, d);
        int r = diameter(root->right, d);
        d = max(d, l + r + 1);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 1;
        diameter(root, d);
        return d - 1;
    }
};
