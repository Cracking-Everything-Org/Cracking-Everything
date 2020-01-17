Given a binary tree, populate an array to represent the averages of all of its levels.

vector<double> findLevelAverages(TreeNode *root) {
  vector<double> result;
  // TODO: Write your code here
  if(!root) return result;
  queue<TreeNode*> queue;
  queue.push(root);
  while(!queue.empty()){
    int size = queue.size();
    double average = 0;
    for(int i=0; i<size; i++){
      TreeNode* current = queue.front();
      queue.pop();
      average+=current->val;
      if(current->left) queue.push(current->left);
      if(current->right) queue.push(current->right);
    }
    average /= size;
    result.push_back(average);
  }
  return result;
}
 
Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for the queue. Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), therefore we will need O(N) space to store them in the queue.
