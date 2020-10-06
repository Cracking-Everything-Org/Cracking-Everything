using namespace std;
#include <stack>
#include <string>

TreeNode* commonAncestor(TreeNode* p, TreeNode* q){
    int heightDif = depth(p) - depth(q);
    TreeNode* first = (delta > 0) ? q : p; //shallower
    TreeNode* second = (delta > 0) ? p : q; //deeper
    //alineo la altura del mayor
    second = heightAlign(second, abs(heightDif));

    //busco la interseccion
    while (first != second && first !=NULL && second !=NULL){
        first=first->parent;
        second=second->parent;
    }
    return (first==NULL || second==NULL) ? NULL : first;
}

TreeNode* heightAlign(TreeNode* second, int &diff){
    while(diff>0 && second !=NULL){
        second = second->parent;
        diff--;
    }
    return second;
}

int depth(TreeNode* node){
    int res = 0;
    while(node!=NULL){
        node=node->parent;
        res++;
    }
    return res;
}
