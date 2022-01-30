class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        return buildTree(vals, 0, vals.size() - 1);
    }
    
    void inorder(TreeNode *root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
    
    TreeNode *buildTree(vector<int>& vals, int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(vals[mid]);
        root->left = buildTree(vals, start, mid - 1);
        root->right = buildTree(vals, mid + 1, end);
        return root;
    }
};