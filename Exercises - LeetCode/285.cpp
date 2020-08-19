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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* minimum = new TreeNode(INT_MIN);
        if (!root || !p) return minimum;
        dfs(root, p, minimum);
        return minimum->val != INT_MIN ? minimum : NULL;
    }

    void dfs(TreeNode* root, TreeNode* p, TreeNode*& minimum) {
        if (!root) return;
        if (root->val > p->val) {
            if (minimum->val != INT_MIN) minimum = minimum->val > root->val ? root : minimum;
            else minimum = root;
        }
        dfs(root->left, p, minimum);
        dfs(root->right, p, minimum);
    }
};
