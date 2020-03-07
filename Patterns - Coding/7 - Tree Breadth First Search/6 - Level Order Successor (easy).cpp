Given a binary tree and a node, find the level order successor of the given node in the tree. The level order successor is the node that appears right after the given node in the level order traversal.

TreeNode *findSuccessor(TreeNode *root, int key) {
 // TODO: Write your code here
 if(!root) return root;
 bool found = false;
 queue<TreeNode*> queue;
 queue.push(root);
 while(!queue.empty()){
   int size = queue.size();
   for(int i=0; i<size; i++){
     TreeNode* current = queue.front();
     queue.pop();
     if(found){
       return current;
     }
     if(current->val == key) found = true;
     if(current->left) queue.push(current->left);
     if(current->right) queue.push(current->right);
   }
 }
 return nullptr;
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for the queue. Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), therefore we will need O(N) space to store them in the queue.
