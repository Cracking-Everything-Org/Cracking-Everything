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

// int i = std::stoi("01000101", nullptr, 2);

#include <string>

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        int total = 0;
        sumPaths(root, total, "");
        return total;
    }

    void sumPaths(TreeNode* root, int& total, string current) {
        if (!root) return;

        current.push_back(root->val);

        if (!root->left && !root->right) {
            total += stoi(current, nullptr, 2);
        }

        sumPaths(root->left, total, current);
        sumPaths(root->right, total, current);
    }
};
