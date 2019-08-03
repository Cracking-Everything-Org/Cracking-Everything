using namespace std;
#include <string>

Node* minimalTree(vector<int> list){
    return minimalTree(list, 0, list.size()-1);
}

Node* minimalTree(vector<int> list, int start, int end){
    if(end<start) return NULL;
    int mid = (start+end)>>1;
    Node* newNode = new Node(list[mid]);
    newNode->left = minimalTree(list,0,mid-1);
    newNode->right = minimalTree(list,mid+1,end);
    return newNode;
}

