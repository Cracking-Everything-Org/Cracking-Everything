/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (!root) return false;
        return searchSequence(root, arr, 0);
    }

    bool searchSequence(TreeNode* root, vector<int>& arr, int index) {
        if (!root || root->val != arr[index]) return false;
        if (index == arr.size() - 1 && (root->left || root->right)) return false;
        if (!root->left && !root->right && index == arr.size() - 1 && root->val == arr[index]) return true;
        return searchSequence(root->left, arr, index + 1) || searchSequence(root->right, arr, index + 1);
    }
};
