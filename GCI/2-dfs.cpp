class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> result;
    vector<int> current;
    findAll(root, sum, current, result);
    return result;
  }

  public:
   static void findAll(TreeNode *root, int sum, vector<int> current, vector<vector<int>> &paths) {
    if (!root) return;
    current.push_back(root->val);
    if (root->val == sum && !root->left && !root->right) {
      paths.push_back(current);
    } else {
      findAll(root->left, sum - root->val, current, paths);
      findAll(root->right, sum - root->val, current, paths);
    }
  }
};