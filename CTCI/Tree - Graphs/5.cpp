using namespace std;
#include <cmath>

bool checkBST(TreeNode* root){
    return checkBST(root, NULL, NULL);
}

bool checkBST(TreeNode* root, int &min, int &max){
    if(!root) return false;

    if((min!=NULL && root.data < min) || (max!=NULL && root.data > max)) return false;

    if(!checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max)) return false;

    return true;
}
