using namespace std;

TreeNode* inorderSuc(TreeNode* n){
    if(!n)return NULL;

    if(n->right){
        return leftMost(n->right);
    }
    else{
        q = n;
        x = q->parent;
        while(x && x->left!=q){
            q = x;
            x = x->parent;
        }
        return x;
    }
}

TreeNode* leftMost(TreeNode* n){
    if(!n) return NULL;
    while(n->left){
        n=n->left;
    }
    return n;
}