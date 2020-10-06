Given a binary tree where each node can only have a digit (0-9) value, each root-to-leaf path will represent a number. Find the total sum of all the numbers represented by all paths.

int findSumOfPathNumbers(TreeNode *root) {
  return findSum(root, 0);
}

 int findSum(TreeNode *root, int currentSum){
  if(!root) return 0;
  currentSum = 10 * currentSum + root->val;
  if(!root->left && !root->right) {
    return currentSum;
  }
  return findSum(root->left, currentSum)
       + findSum(root->right, currentSum);
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack. The worst case will happen when the given tree is a linked list (i.e., every node has only one child).
