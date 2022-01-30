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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        if (!root) return averages;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            double average = 0;
            double total = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                total += current->val;
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            average = double(total / size);
            averages.push_back(average);
        }
        return averages;
    }
};
