class MinimumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    int minDepth = 0;
    if (!root) return minDepth;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      minDepth++;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode* current = q.front();
        q.pop();
        if (!current->left && !current->right) return minDepth; 
        if (current->left) q.push(current->left); 
        if (current->right) q.push(current->right); 
      }
    }
    return minDepth;
  }
};