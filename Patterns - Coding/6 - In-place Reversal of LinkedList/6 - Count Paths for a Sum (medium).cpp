Given a binary tree and a number ‘S’, find all paths in the tree such that the sum of all the node values of each path equals ‘S’. Please note that the paths can start or end at any node but all paths must follow direction from parent to child (top to bottom).

int countPaths(TreeNode *root, int S) {
  // TODO: Write your code here
  return pathsCount(root, S);
}

int pathsCount(TreeNode *root, int S){
  if(!root) return 0;
  if(!root->left && !root->right && root->val == S){
    return 1;
  }
  return pathsCount(root->left, S - root->val)
       + pathsCount(root->right, S - root->val)
       + pathsCount(root->left, S)
       + pathsCount(root->right, S);
}

// sol

static int countPaths(TreeNode *root, int S) {
  vector<int> currentPath;
  return countPathsRecursive(root, S, currentPath);
}

static int countPathsRecursive(TreeNode *currentNode, int S, vector<int> &currentPath) {
  if (currentNode == nullptr) {
    return 0;
  }

  // add the current node to the path
  currentPath.push_back(currentNode->val);
  int pathCount = 0, pathSum = 0;
  // find the sums of all sub-paths in the current path list
  for (vector<int>::reverse_iterator itr = currentPath.rbegin(); itr != currentPath.rend();
       ++itr) {
    pathSum += *itr;
    // if the sum of any sub-path is equal to 'S' we increment our path count.
    if (pathSum == S) {
      pathCount++;
    }
  }

  // traverse the left sub-tree
  pathCount += countPathsRecursive(currentNode->left, S, currentPath);
  // traverse the right sub-tree
  pathCount += countPathsRecursive(currentNode->right, S, currentPath);

  // remove the current node from the path to backtrack,
  // we need to remove the current node while we are going up the recursive call stack.
  currentPath.pop_back();

  return pathCount;
}

Time complexity #
The time complexity of the above algorithm is O(N^2) in the worst case, where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once, but for every node, we iterate the current path. The current path, in the worst case, can be O(N) (in the case of a skewed tree). But, if the tree is balanced, then the current path will be equal to the height of the tree, i.e., O(logN). So the best case of our algorithm will be O(NlogN).

Space complexity #
The space complexity of the above algorithm will be O(N). This space will be used to store the recursion stack. The worst case will happen when the given tree is a linked list (i.e., every node has only one child). We also need O(N) space for storing the currentPath in the worst case.

Overall space complexity of our algorithm is O(N).
