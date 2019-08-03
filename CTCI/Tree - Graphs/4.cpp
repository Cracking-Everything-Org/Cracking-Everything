using namespace std;
#include <cmath>

bool isBalanced(TreeNode* root){
    return (checkHeight(root) != INT_MIN);
}

int checkHeight(TreeNode* root){
    if(!root) return NULL;
    int leftHeight = checkHeight(root->left);
    if(leftHeight == INT_MIN) return INT_MIN;

    int rightHeight = checkHeight(root->right);
    if(rightHeight == INT_MIN) return INT_MIN;

    int dif = leftHeight - rightHeight;
    if(abs(dif)>1) return INT_MIN;
    else return (fmax(leftHeight, rightHeight) +1);
}