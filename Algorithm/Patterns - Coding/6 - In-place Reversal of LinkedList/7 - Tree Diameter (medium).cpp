Given a binary tree, find the length of its diameter. The diameter of a tree is the number of nodes on the longest path between any two leaf nodes. The diameter of a tree may or may not pass through the root.

int findDiameter(TreeNode *root) {
  int treeDiameter = 0;
  calculateHight(root, treeDiameter);
  return treeDiameter;
}

static int calculateHight(TreeNode *currentNode, int &treeDiameter) {
  if (currentNode == nullptr) {
    return 0;
  }

  int leftTreeHeight = calculateHight(currentNode->left, treeDiameter);
  int rightTreeHeight = calculateHight(currentNode->right, treeDiameter);

  // diameter at the current node will be equal to the height of left subtree +
  // the height of right sub-trees + '1' for the current node
  int diameter = leftTreeHeight + rightTreeHeight + 1;

  // update the global tree diameter
  treeDiameter = max(treeDiameter, diameter);

  // height of the current node will be equal to the maximum of the hights of
  // left or right subtrees plus '1' for the current node
  return max(leftTreeHeight, rightTreeHeight) + 1;
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack. The worst case will happen when the given tree is a linked list (i.e., every node has only one child).
