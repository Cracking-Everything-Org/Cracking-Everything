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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return NULL;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == rightHeight) return root;
        else if (leftHeight > rightHeight) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);
    }

    unordered_map<TreeNode*, int> ht;

    int getHeight(TreeNode* root) {
        if (ht.find(root) != ht.end()) return ht[root];
        if (!root) return 0;
        int res = max(getHeight(root->left), getHeight(root->right)) + 1;
        ht[root] = res;
        return res;
    }

};
