class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> current;
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode* front = q.front();
        q.pop();
        current.push_back(front->val);
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
      }
      result.push_back(current);
    }
    return result;
  }
};