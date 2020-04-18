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

    // PUSHEO LA DIAGONAL EN UN STACK

    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;

        // we could run an INORDER TRAVERSAL and store the values in a vector and check if it is sorted
        // but we will waste memory
        // instead we will compare the root value with its left node value

        int leftChildVal = INT_MIN;
        while (!stk.empty() || root != NULL) {
            while (root != NULL) {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            if (root->val <= leftChildVal) return false;  // check if it is valid (root->val <= root->left->val)
            leftChildVal = root->val;
            root = root->right;
        }

        return true;
    }
};
