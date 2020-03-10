class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        sumBST(root, L, R, sum);
        return sum;
    }

    void sumBST(TreeNode* root, int L, int R, int &sum) {
        if(!root) return;
        if(root->val >= L && root->val <= R){
            sum += root->val;
        }
        sumBST(root->left, L, R, sum);
        sumBST(root->right, L, R, sum);
    }
};
