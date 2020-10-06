using namespace std;
#include <queue>

vector<queue> createLevelQueue(TreeNode* root){
    vector<queue> lists;
    createLevelQueue(root, lists, 0);
    return lists;
}

void createLevelQueue(TreeNode* root, vector<queue> lists, int level){
    if(!root) return NULL;

    queue* list;
    if(lists[level]==NULL){
        lists[level]=list;
    }else{
        list=list[level];
    }
    list.push(root);
    createLevelQueue(root->left, lists, level+1);
    createLevelQueue(root->right, lists, level+1);
}
