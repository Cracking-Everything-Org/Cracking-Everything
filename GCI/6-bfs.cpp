class LevelOrderSuccessor {
 public:
  static TreeNode *findSuccessor(TreeNode *root, int key) {
    TreeNode* result;
    if (!root) return result;
    bool found = false;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode* current = q.front();
        q.pop();
        if (found) return current;
        if (current->val == key) found = true;
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
      }
    }
    return result;
  }
};