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
        vector<vector<int>> result;
        vector<int> current;
        path(root, sum, current, result);
        return result;
    }

    void path(TreeNode* root, int sum, vector<int> current, vector<vector<int>>& result){
        if(!root) return;
        current.push_back(root->val);
        if(!root->left && !root->right && sum == root->val){
            result.push_back(current);
            return;
        }
        vector<int> leftvector(current);
        vector<int> rightvector(current);
        path(root->left, sum - root->val, current, result);
        path(root->right, sum - root->val, current, result);
    }
};
