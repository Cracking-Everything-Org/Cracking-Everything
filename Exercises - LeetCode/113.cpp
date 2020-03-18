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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> current;
        findPaths(root, sum, current, paths);
        return paths;
    }

    void findPaths(TreeNode* root, int sum, vector<int> current, vector<vector<int>>& paths) {
        if (!root) return ;
        current.push_back(root->val);
        if (sum == root->val && !root->left && !root->right) {
            paths.push_back(current);
        }
        findPaths(root->left, sum - root->val, current, paths);
        findPaths(root->right, sum - root->val, current, paths);
    }
};
