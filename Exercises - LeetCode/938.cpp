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

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int count = 0;
        findSum(root, low, high, count);
        return count;
    }
    
    void findSum(TreeNode* root, int low, int high, int& count) {
        if (root) {
            if (root->val >= low && root->val <= high) {
                count += root->val;
            }
            findSum(root->left, low, high, count);
            findSum(root->right, low, high, count);
        }
    }
};
