class SumOfPathNumbers {
 public:
  static int findSumOfPathNumbers(TreeNode *root) {
    return sumOfPaths(root, 0);
  }
 public:
  static int sumOfPaths(TreeNode *root, int current) {
    if (!root) return 0;
    current = 10 * current + root->val;
    if (!root->left && !root->right) return current;
    return sumOfPaths(root->left, current) + sumOfPaths(root->right, current); 
  } 
};