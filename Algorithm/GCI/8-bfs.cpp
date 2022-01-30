class ConnectAllSiblings {
 public:
  static void connect(TreeNode *root) {
   if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* previous = nullptr;
    while (!q.empty()) {
      int size = q.size();
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