Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.

bool findPath(TreeNode *root, const vector<int> &sequence) {
  // TODO: Write your code here
  return hasPath(root, sequence, 0);
}

bool hasPath(TreeNode* root, vector<int> sequence, int position){
  if(!root || position >= sequence.size()) return false;

  if(root->val == sequence[position]
  && !root->left
  && !root->right
  && position == sequence.size() - 1){
    return true;
  }

  return root->val == sequence[position]
  && (hasPath(root->left, sequence, position + 1)
    || hasPath(root->right, sequence, position + 1));
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) in the worst case. This space will be used to store the recursion stack. The worst case will happen when the given tree is a linked list (i.e., every node has only one child).
