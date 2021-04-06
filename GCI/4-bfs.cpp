class LevelAverage {
 public:
  static vector<double> findLevelAverages(TreeNode *root) {
    vector<double> avarages;
    if (!root) return avarages;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      double sum = 0;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode* current = q.front();
        q.pop();
        sum += current->val;
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
      }
      avarages.push_back(sum / size);
    }
    return avarages;
  }
};