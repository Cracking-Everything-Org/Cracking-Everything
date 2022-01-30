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
    int fromRootSum(TreeNode* root, int sum) {
        if (!root) return 0;
        if (sum == root->val) {
            // sigo fijandome pq hay nodos negativos, por lo tanto pueden existir otros caminos
            return 1 + fromRootSum(root->left, 0) + fromRootSum(root->right, 0);
        }
        return fromRootSum(root->left, sum - root->val) + fromRootSum(root->right, sum - root->val);
    }

    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int result = fromRootSum(root, sum);
        result += pathSum(root->left, sum) + pathSum(root->right, sum);
        return result;
    }
};
