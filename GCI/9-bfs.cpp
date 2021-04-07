class RightViewTree {
 public:
  static vector<TreeNode *> traverse(TreeNode *root) {
    vector<TreeNode*> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode* current = q.front();
        q.pop();
        if (i == size - 1) result.push_back(current);
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
      }
    }
    return result;
  }
};