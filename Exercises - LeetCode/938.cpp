class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        calcRangeSum(root, sum, L, R);
        return sum;
    }

    void calcRangeSum(TreeNode* root, int &sum, int L, int R) {
        if (!root) return;
        if (root->val >= L && root->val <= R) {
            sum += root->val;
        }
        calcRangeSum(root->left, sum, L, R);
        calcRangeSum(root->right, sum, L, R);
    }
};
