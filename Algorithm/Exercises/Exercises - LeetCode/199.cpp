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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if (!root) return rightView;
        queue<TreeNode*> levels;
        levels.push(root);
        while (!levels.empty()) {
            int size = levels.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = levels.front();
                levels.pop();
                if (i == size - 1) {
                    rightView.push_back(current->val);
                }
                if (current->left) {
                    levels.push(current->left);
                }
                if (current->right) {
                    levels.push(current->right);
                }
            }
        }
        return rightView;
    }
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSide;
        if (!root) return rightSide;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                if (i == size - 1) rightSide.push_back(current->val);
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
        return rightSide;
    }
};