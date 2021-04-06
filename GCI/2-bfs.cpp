class ReverseLevelOrderTraversal {
 public:
  static deque<vector<int>> traverse(TreeNode *root) {
    deque<vector<int>> result;
    if (!root) {
      return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> level;
      for (int i = 0; i < size; i++) {
        TreeNode* current = q.front();
        q.pop();
        level.push_back(current->val);
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
      }
      result.push_front(level);
    }
    return result;
  }
};