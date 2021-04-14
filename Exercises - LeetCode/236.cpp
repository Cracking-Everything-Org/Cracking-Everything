class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        
        if (root == p || root == q) return root;
        
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
        
        if (leftLCA && rightLCA) {
            return root;
        }
        
        return leftLCA ? leftLCA : rightLCA;
    }
};
