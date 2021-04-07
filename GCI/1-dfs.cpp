class TreePathSum {
 public:
  static bool hasPath(TreeNode *root, int sum) {
    if (!root) return false;
    if (sum == root->val && !root->left && !root->right) return true; 
    return hasPath(root->left, sum - root->val) || hasPath(root->right, sum - root->val);
  }
};