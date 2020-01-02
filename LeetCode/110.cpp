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
    bool isBalanced(TreeNode* root) {
        if(!root)   return true;
        int left_depth=help(root->left);
        int right_depth=help(root->right);
        return abs(left_depth-right_depth) <= 1
            && isBalanced(root->left)
            && isBalanced(root->right);
    }

    int help(TreeNode* root){
        if(!root)  return 0;
        return max(help(root->left), help(root->right))+1;
    }
};
