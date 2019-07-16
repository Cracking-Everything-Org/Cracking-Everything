#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool is_valid(const vector<Node>& tree, int root, long long min, long long max) {
  if (tree.size() == 0) return true;
  if (tree[root].left == -1 && tree[root].right == -1 &&
      tree[root].key < max && tree[root].key > min) {
    return true;
  }
  if (tree[root].key > min && tree[root].key < max) {
    bool left = true, right = true;
    if (tree[root].left != -1) {
      left = false;
      left = is_valid(tree, tree[root].left, min, tree[root].key);
    }
    if (tree[root].right != -1) {
      right = false;
      right = is_valid(tree, tree[root].right, tree[root].key, max);
    }
    if (left && right) return true;
  }
  return false;
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  return is_valid(tree, 0, -10000000000, 10000000000);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}