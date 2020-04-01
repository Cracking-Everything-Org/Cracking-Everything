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
    int closestValue(TreeNode* root, double target) {
        int closest = INT_MAX;
        closestVal(root, target, closest);
        return closest;
    }

    void closestVal(TreeNode* root, double target, int & closest) {
        if (!root) return;
        if (closest == INT_MAX) closest = root->val;
        if ( abs(round(target) - root->val) < abs(round(target) - closest)  ) closest = root->val;

        if (root->val < target) closestVal(root->right, target, closest);
        if (root->val > target) closestVal(root->left, target, closest);
    }
};
