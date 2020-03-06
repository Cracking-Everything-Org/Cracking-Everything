Find the path with the maximum sum in a given binary tree. Write a function that returns the maximum sum. A path can be defined as a sequence of nodes between any two nodes and doesn’t necessarily pass through the root.

int findMaximumPathSum(TreeNode *root) {
  int globalMaximumSum = numeric_limits<int>::min();
  findMaximumPathSumRecursive(root, globalMaximumSum);
  return globalMaximumSum;
}

static int findMaximumPathSumRecursive(TreeNode *currentNode, int &globalMaximumSum) {
  if (currentNode == nullptr) {
    return 0;
  }

  int maxPathSumFromLeft = findMaximumPathSumRecursive(currentNode->left, globalMaximumSum);
  int maxPathSumFromRight = findMaximumPathSumRecursive(currentNode->right, globalMaximumSum);

  // ignore paths with negative sums, since we need to find the maximum sum we should
  // ignore any path which has an overall negative sum.
  maxPathSumFromLeft = max(maxPathSumFromLeft, 0);
  maxPathSumFromRight = max(maxPathSumFromRight, 0);

  // maximum path sum at the current node will be equal to the sum from the left subtree +
  // the sum from right subtree + val of current node
  int localMaximumSum = maxPathSumFromLeft + maxPathSumFromRight + currentNode->val;

  // update the global maximum sum
  globalMaximumSum = max(globalMaximumSum, localMaximumSum);

  // maximum sum of any path from the current node will be equal to the maximum of
  // the sums from left or right subtrees plus the value of the current node
  return max(maxPathSumFromLeft, maxPathSumFromRight) + currentNode->val;
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack. The worst case will happen when the given tree is a linked list (i.e., every node has only one child).
