class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int maxSum = root->val;
        traverse(root, maxSum);
        return maxSum;
    }
    
    int traverse(TreeNode* root, int& maxSum) {
        if (!root) return 0;
        int leftPath = max(traverse(root->left, maxSum), 0);
        int rightPath = max(traverse(root->right, maxSum), 0);
        //global
        maxSum = max(maxSum, leftPath + rightPath + root->val);
        //lobal
        return root->val + max(leftPath, rightPath);
    }
    // O(n), no visitamos cada nodo mas que 2 veces
    // O(H)
};
