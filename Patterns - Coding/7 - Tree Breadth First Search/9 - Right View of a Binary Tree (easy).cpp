Given a binary tree, return an array containing nodes in its right view. The right view of a binary tree is the set of nodes visible when the tree is seen from the right side.

vector<TreeNode *> traverse(TreeNode *root) {
  vector<TreeNode *> result;
  // TODO: Write your code here
  if(!root) return result;
  queue<TreeNode*> queue;
  queue.push(root);
  while(!queue.empty()){
    int size = queue.size();
    for (int i=0; i<size; i++){
      TreeNode* current = queue.front();
      queue.pop();
      if(i == size - 1) result.push_back(current);
      if(current->left) queue.push(current->left);
      if(current->right) queue.push(current->right);
    }
  }
  return result;
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) as we need to return a list containing the level order traversal. We will also need O(N) space for the queue. Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), therefore we will need O(N) space to store them in the queue.
