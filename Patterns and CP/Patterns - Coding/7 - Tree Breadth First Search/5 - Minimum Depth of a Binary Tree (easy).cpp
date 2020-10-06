Find the minimum depth of a binary tree. The minimum depth is the number of nodes along the shortest path from the root node to the nearest leaf node.

int findDepth(TreeNode *root) {
  int minimumTreeDepth = 0;
  // TODO: Write your code here
  if(!root) return minimumTreeDepth;
  minimumTreeDepth =  1;
  queue<TreeNode*> queue;
  queue.push(root);
  while(!queue.empty()){
    int size = queue.size();
    for (int i=0; i<size; i++){
      TreeNode* current = queue.front();
      queue.pop();
      if(!current->left && !current->right) return minimumTreeDepth;
      if(current->left) queue.push(current->left);
      if(current->right) queue.push(current->right);
    }
    minimumTreeDepth++;
  }
  return minimumTreeDepth;
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for the queue. Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), therefore we will need O(N) space to store them in the queue.
