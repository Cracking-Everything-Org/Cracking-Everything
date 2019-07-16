#include <cstdio>

struct Vertex {
  int key;
  long long sum;
  Vertex *left;
  Vertex *right;
  Vertex *parent;

  Vertex(int key, long long sum, Vertex *left, Vertex *right, Vertex *parent)
      : key(key), sum(sum), left(left), right(right), parent(parent) {}
};

void update(Vertex *v) {
  if (v == NULL)
    return;
  v->sum = v->key + (v->left != NULL ? v->left->sum : 0ll) +
           (v->right != NULL ? v->right->sum : 0ll);
  if (v->left != NULL) {
    v->left->parent = v;
  }
  if (v->right != NULL) {
    v->right->parent = v;
  }
}

void small_rotation(Vertex *v) {
  Vertex *parent = v->parent;
  if (parent == NULL) {
    return;
  }
  Vertex *grandparent = v->parent->parent;
  if (parent->left == v) {
    Vertex *m = v->right;
    v->right = parent;
    parent->left = m;
  } else {
    Vertex *m = v->left;
    v->left = parent;
    parent->right = m;
  }
  update(parent);
  update(v);
  v->parent = grandparent;
  if (grandparent != NULL) {
    if (grandparent->left == parent) {
      grandparent->left = v;
    } else {
      grandparent->right = v;
    }
  }
}

void big_rotation(Vertex *v) {
  if (v->parent->left == v && v->parent->parent->left == v->parent) {
    small_rotation(v->parent);
    small_rotation(v);
  } else if (v->parent->right == v && v->parent->parent->right == v->parent) {
    small_rotation(v->parent);
    small_rotation(v);
  } else {
    small_rotation(v);
    small_rotation(v);
  }
}
void splay(Vertex *&root, Vertex *v) {
  if (v == NULL)
    return;
  while (v->parent != NULL) {
    if (v->parent->parent == NULL) {
      small_rotation(v);
      break;
    }
    big_rotation(v);
  }
  root = v;
}

Vertex *find(Vertex *&root, int key) {
  Vertex *v = root;
  Vertex *last = root;
  Vertex *next = NULL;
  while (v != NULL) {
    if (v->key >= key &&
        (next == NULL ||
         v->key < next->key)) {
      next = v;
    }
    last = v;
    if (v->key == key) {
      break;
    }
    if (v->key < key) {
      v = v->right;
    } else {
      v = v->left;
    }
  }
  splay(root, last);
  return next;
}

void split(Vertex *root, int key, Vertex *&left, Vertex *&right) {
  right = find(root, key);
  splay(root, right);
  if (right == NULL) {
    left = root;
    return;
  }
  left = right->left;
  right->left = NULL;
  if (left != NULL) {
    left->parent = NULL;
  }
  update(left);
  update(right);
}

Vertex *merge(Vertex *left, Vertex *right) {
  if (left == NULL)
    return right;
  if (right == NULL)
    return left;
  Vertex *min_right = right;
  while (min_right->left != NULL) {
    min_right = min_right->left;
  }
  splay(right, min_right);
  right->left = left;
  update(right);
  return right;
}

Vertex *root = NULL;

void insert(int x) {
  Vertex *left = NULL;
  Vertex *right = NULL;
  Vertex *new_vertex = NULL;
  split(root, x, left, right);
  if (right == NULL || right->key != x) {
    new_vertex = new Vertex(x, x, NULL, NULL, NULL);
  }
  root = merge(merge(left, new_vertex), right);
}

bool find(int x) {
  Vertex *ans = find(root, x);
  if (ans != NULL && ans->key == x)
    return true;
  else
    return false;
}
void erase(int x) {
  if (!root || find(x) == false)
    return;
  Vertex *w = root;
  if (root->left == NULL) {
    root = root->right;
    if (root)
      root->parent = NULL;

  } else if (root->right == NULL) {
    root = root->left;
    if (root)
      root->parent = NULL;
  } else {
    Vertex *lt = root->left;
    lt->parent = NULL;
    root->left = NULL;
    root = root->right;
    root->parent = NULL;
    bool temp = find(w->key);
    root->left = lt;
    lt->parent = root;
  }
  delete w;
  if (root)
    update(root);
}
long long sum(int from, int to) {
  Vertex *left = NULL;
  Vertex *middle = NULL;
  Vertex *right = NULL;
  split(root, from, left, middle);
  split(middle, to + 1, middle, right);
  long long ans = 0;
  if (middle)
    ans = middle->sum;
  middle = merge(middle, right);
  root = merge(left, middle);
  return ans;
}

const int MODULO = 1000000001;

int main() {
  int n;
  scanf("%d", &n);
  int last_sum_result = 0;
  for (int i = 0; i < n; i++) {
    char buffer[10];
    scanf("%s", buffer);
    char type = buffer[0];
    switch (type) {
    case '+': {
      int x;
      scanf("%d", &x);
      insert((x + last_sum_result) % MODULO);
    } break;
    case '-': {
      int x;
      scanf("%d", &x);
      erase((x + last_sum_result) % MODULO);
    } break;
    case '?': {
      int x;
      scanf("%d", &x);
      printf(find((x + last_sum_result) % MODULO) ? "Found\n" : "Not found\n");
    } break;
    case 's': {
      int l, r;
      scanf("%d %d", &l, &r);
      long long res =
          sum((l + last_sum_result) % MODULO, (r + last_sum_result) % MODULO);
      printf("%lld\n", res);
      last_sum_result = int(res % MODULO);
    }
    }
  }
  return 0;
}