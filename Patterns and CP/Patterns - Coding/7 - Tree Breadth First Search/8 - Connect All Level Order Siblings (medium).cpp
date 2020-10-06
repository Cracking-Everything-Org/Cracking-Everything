Given a binary tree, connect each node with its level order successor. The last node of each level should point to the first node of the next level.

void connect(TreeNode *root) {
 // TODO: Write your code here
 if(!root) return;
 queue<TreeNode*> queue;
 queue.push(root);
 TreeNode* previous = NULL;
 TreeNode* current = NULL;
 while(!queue.empty()){
    current = queue.front();
    queue.pop();
    if(previous) previous->next = current;
    previous = current;
    if(current->left) queue.push(current->left);
    if(current->right) queue.push(current->right);
 }
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) which is required for the queue. Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), therefore we will need O(N) space to store them in the queue.
