class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    // TODO: Write your code here
    if(!root) return result;
    int level = 1;
    queue<TreeNode*> queue;
    queue.push(root);
    while(!queue.empty()){
      int size = queue.size();
      vector<int> currentLevel;
      for(int i=0; i<size; i++){
        TreeNode* currentNode = queue.front();
        queue.pop();
        currentLevel.push_back(currentNode->val);
        if(currentNode->left) queue.push(currentNode->left);
        if(currentNode->right) queue.push(currentNode->right);
      }
      if(level % 2 == 0){
        reverse(currentLevel.begin(), currentLevel.end());
      }
      level++;
      result.push_back(currentLevel);
    }
    return result;
  }
};