Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf such that the sum of all the node values of that path equals ‘S’.

bool hasPath(TreeNode *root, int sum) {
  if (root == nullptr) {
    return false;
  }

  // if the current node is a leaf and its value is equal to the sum, we've found a path
  if (root->val == sum && root->left == nullptr && root->right == nullptr) {
    return true;
  }

  // recursively call to traverse the left and right sub-tree
  // return true if any of the two recursive call return true
  return hasPath(root->left, sum - root->val) || hasPath(root->right, sum - root->val);
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack. The worst case will happen when the given tree is a linked list (i.e., every node has only one child).
