#include <algorithm>
#include <iostream>

class Node {
 public:
  int data;
  int height;
  Node* left_child;
  Node* right_child;
  explicit Node(int key);
};

Node::Node(int key) {
  data = key;
  height = 1;
  left_child = nullptr;
  right_child = nullptr;
}

class AVLTree {
 private:
  Node* root_;

 public:
  AVLTree();
  ~AVLTree();
  void DestroyTree(Node* p);
  static int Height(Node* p);
  static int BalanceFactor(Node* p);
  static Node* RotateLeft(Node* p);
  static Node* RotateRight(Node* p);
  Node* Insert(Node* p, int key);
  static int Next(Node* p, int key);
  Node* GetRoot() { return root_; }
  void SetRoot(Node* node) { root_ = node; }  // Added function to set the root
};

AVLTree::AVLTree() { root_ = nullptr; }
AVLTree::~AVLTree() { DestroyTree(root_); }

void AVLTree::DestroyTree(Node* p) {
  if (p != nullptr) {
    DestroyTree(p->left_child);
    DestroyTree(p->right_child);
    delete p;
  }
}

int AVLTree::Height(Node* p) {
  if (p == nullptr) {
    return 0;
  }

  int height_left;
  int height_right;
  height_left = (p->left_child != nullptr) ? p->left_child->height : 0;
  height_right = (p->right_child != nullptr) ? p->right_child->height : 0;
  return std::max(height_left, height_right) + 1;
}

int AVLTree::BalanceFactor(Node* p) {
  if (p == nullptr) {
    return 0;
  }

  int hl;
  int hr;
  hl = Height(p->left_child);
  hr = Height(p->right_child);
  return hl - hr;
}

Node* AVLTree::RotateRight(Node* p) {
  Node* left_child_temp = p->left_child;
  Node* right_grandchild = left_child_temp->right_child;
  p->left_child = right_grandchild;
  left_child_temp->right_child = p;

  p->height = std::max(Height(p->left_child), Height(p->right_child)) + 1;
  left_child_temp->height = std::max(Height(left_child_temp->left_child),
                                     Height(left_child_temp->right_child)) +
                            1;

  return left_child_temp;
}

Node* AVLTree::RotateLeft(Node* p) {
  Node* right_child_temp = p->right_child;
  Node* left_grandchild = right_child_temp->left_child;
  p->right_child = left_grandchild;
  right_child_temp->left_child = p;

  p->height = std::max(Height(p->left_child), Height(p->right_child)) + 1;
  right_child_temp->height = std::max(Height(right_child_temp->left_child),
                                      Height(right_child_temp->right_child)) +
                             1;

  return right_child_temp;
}

Node* AVLTree::Insert(Node* p, int key) {
  if (p == nullptr) {
    return new Node(key);
  }

  if (key < p->data) {
    p->left_child = Insert(p->left_child, key);
  } else if (key > p->data) {
    p->right_child = Insert(p->right_child, key);
  }

  p->height = std::max(Height(p->left_child), Height(p->right_child)) + 1;
  if (BalanceFactor(p) > 1) {
    if (BalanceFactor(p->left_child) < 0) {
      p->left_child = RotateLeft(p->left_child);  // Left-Right Case
    }
    return RotateRight(p);  // Left-Left Case
  }
  if (BalanceFactor(p) < -1) {
    if (BalanceFactor(p->right_child) > 0) {
      p->right_child = RotateRight(p->right_child);  // Right-Left Case
    }
    return RotateLeft(p);  // Right-Right Case
  }

  return p;
}

int AVLTree::Next(Node* p, int key) {
  int next_value = -1;

  while (p != nullptr) {
    if (p->data >= key) {
      next_value = p->data;
      p = p->left_child;
    } else {
      p = p->right_child;
    }
  }

  return next_value;
}

int main() {
  int queries;
  std::cin >> queries;
  AVLTree avltree;
  int last_result = 0;
  for (int i = 0; i < queries; i++) {
    char operation;
    int value;
    std::cin >> operation;
    std::cin >> value;
    if (operation == '+') {
      value = (value + last_result) % 1000000000;
      avltree.SetRoot(avltree.Insert(avltree.GetRoot(), value));
      last_result = 0;
    } else if (operation == '?') {
      last_result = avltree.Next(avltree.GetRoot(), value);
      std::cout << last_result << "\n";
    }
  }

  return 0;
}
