class PathWithGivenSequence {
 public:
  static bool findPath(TreeNode *root, const vector<int> &sequence) {
    if (root == nullptr) {
      return sequence.empty();
    }
    return hasPath(root, sequence, 0);
  }

 public:
  static bool hasPath(TreeNode *root, const vector<int> &sequence, int pos) {
    if (!root) return false;
    if (pos >= sequence.size() || root->val != sequence[pos]) return false;
    if (!root->left && !root->right && pos == sequence.size() - 1) return true;
    return hasPath(root->left, sequence, pos + 1) || hasPath(root->right, sequence, pos + 1);
  }
};