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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, 0, preorder.size());
    }

    TreeNode* buildBST(vector<int>& preorder, int start, int end) {
        TreeNode* root = new TreeNode(preorder[start]);
        int index = start + 1;
        while (index < end && preorder[index] < preorder[start]) {
            index++;
        }
        if (index > start + 1)
            root->left = buildBST(preorder, start + 1, index);
        if (index < end)
            root->right = buildBST(preorder, index, end);
        return root;
    }
};
