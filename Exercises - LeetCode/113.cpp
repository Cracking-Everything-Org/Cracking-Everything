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
        searchPaths(paths, current, root, sum);
        return paths;
    }

    void searchPaths(vector<vector<int>>& paths, vector<int> current, TreeNode* root, int sum) {
        if (!root) return;

        current.push_back(root->val);

        if (!root->left && !root->right && root->val == sum) {
            paths.push_back(current);
        }

        searchPaths(paths, current, root->left, sum - root->val);
        searchPaths(paths, current, root->right, sum - root->val);
    }
};
