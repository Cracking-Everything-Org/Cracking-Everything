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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (!root) return levels;
        queue<TreeNode*> q;
        q.push(root);
        bool shouldReverse = false;
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                level.push_back(current->val);
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            if (shouldReverse) reverse(level.begin(), level.end());
            shouldReverse = !shouldReverse;
            levels.push_back(level);
        }
        return levels;
    }
};
