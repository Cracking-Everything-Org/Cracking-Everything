Given a binary tree, return an array containing all the boundary nodes of the tree in an anti-clockwise direction.

The boundary of a tree contains all nodes in the left view, all leaves, and all nodes in the right view. Please note that there should not be any duplicate nodes. For example, the root is only included in the left view; similarly, if a level has only one node we should include it in the left view.

vector<TreeNode *> findLeavesDFS(TreeNode *root) {
  vector<TreeNode *> leaves;
  stack<TreeNode *> stk;
  stk.push(root);
  while (!stk.empty()) {
    TreeNode *currentNode = stk.top();
    stk.pop();
    if (currentNode->left == nullptr && currentNode->right == nullptr) {
      leaves.push_back(currentNode);
    }

    // insert the children of current node in the stack
    // add the right child first, this way left child will be at the top and processed first
    if (currentNode->right != nullptr) {
      stk.push(currentNode->right);
    }
    if (currentNode->left != nullptr) {
      stk.push(currentNode->left);
    }
  }
  return leaves;
}


vector<TreeNode *> findBoundary(TreeNode *root) {
  if (root == nullptr) {
    return vector<TreeNode *>();
  }

  vector<TreeNode *> leftView;
  deque<TreeNode *> rightView;

  queue<TreeNode *> queue;
  queue.push(root);
  while (!queue.empty()) {
    int levelSize = queue.size();
    for (int i = 0; i < levelSize; i++) {
      TreeNode *currentNode = queue.front();
      queue.pop();

      if (currentNode->left == nullptr && currentNode->right == nullptr) {
        continue;           // skip leaf nodes
      } else if (i == 0) {  // if it is the first node of this level, add it to the leftView
        leftView.push_back(currentNode);
      } else if (i == levelSize -
                          1) {  // if it is the last node of this level, add it to the rightView
        // because of ant-clockwise direction, we need to populate rightView in the reverse
        // direction
        rightView.push_front(currentNode);
      }

      // insert the children of current node in the queue
      if (currentNode->left != nullptr) {
        queue.push(currentNode->left);
      }
      if (currentNode->right != nullptr) {
        queue.push(currentNode->right);
      }
    }
  }

  vector<TreeNode *> leaves = findLeavesDFS(root);

  vector<TreeNode *> result;
  result.insert(result.end(), leftView.begin(), leftView.end());
  result.insert(result.end(), leaves.begin(), leaves.end());
  std::copy(std::begin(rightView), std::end(rightView), std::back_inserter(result));
  return result;
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node twice, one for BFS and one for DFS.

Space complexity #
The space complexity of the above algorithm will be O(N) as we need to return a list containing the boundary nodes. We will also need O(N) space for the queue. Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level of a complete binary tree), therefore we will need O(N) space to store them in the queue. We will also need O(N) space for DFS.
