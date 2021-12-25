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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int maximum = 0;
        findDepth(root, 0, maximum);        
        return maximum;
    }
    
    void findDepth(TreeNode* root, int current, int& maximum) {
        if (root) {
            current++;
            maximum = max(maximum, current);
            findDepth(root->left, current, maximum);
            findDepth(root->right, current, maximum);
        }
    }
};