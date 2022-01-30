class ConnectLevelOrderSiblings {
 public:
  static void connect(TreeNode *root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      TreeNode* previous = nullptr;
      for (int i = 0; i < size; i++) {
        TreeNode* current = q.front();
        q.pop();
        if (previous) previous->next = current;
        previous = current;
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
      }
    }
  }
};