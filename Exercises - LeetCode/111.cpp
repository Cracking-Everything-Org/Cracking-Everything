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
    int minDepth(TreeNode* root) {
        int minLevel = 0;
        if (!root) return minLevel;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                if (!current->left && !current->right) return minLevel + 1;
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            minLevel++;
        }
        return minLevel + 1;
    }
};
