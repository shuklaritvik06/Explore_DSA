#include <iostream>
#include <string>

struct Node {
  char data;
  Node *next;
};

class List {
private:
  Node *head_;

  Node *AddNodesRecursively_(std::string str, int index);
  void DeleteNodesRecursively_(Node *node);

public:
  explicit List(std::string str);
  ~List();
  Node *ReverseLinkedList_(Node *current, Node *prev);
  void DisplayLinkedList_(Node *node);
  Node *get_head_() { return head_; }
};

List::List(std::string str) {
  head_ = nullptr;
  AddNodesRecursively_(str, 0);
}

List::~List() { DeleteNodesRecursively_(head_); }

Node *List::AddNodesRecursively_(std::string str, int index) {
  if (index >= str.length()) {
    return nullptr;
  }
  Node *new_node = new Node;
  new_node->data = str[index];
  new_node->next = AddNodesRecursively_(str, index + 1);
  head_ = new_node;
  return new_node;
}

void List::DisplayLinkedList_(Node *head_) {
  if (head_ != nullptr) {
    std::cout << head_->data;
    DisplayLinkedList_(head_->next);
  }
}

Node *List::ReverseLinkedList_(Node *current, Node *prev) {
  if (current == nullptr) {
    head_ = prev;
    return head_;
  }
  Node *next = current->next;
  current->next = prev;
  ReverseLinkedList_(next, current);
  return head_;
}

void List::DeleteNodesRecursively_(Node *node) {
  if (node == nullptr) {
    return;
  }
  DeleteNodesRecursively_(node->next);
  delete node;
}

int main() {
  std::string str;
  std::getline(std::cin, str);
  List myList{str};
  myList.ReverseLinkedList_(myList.get_head_(), nullptr);
  myList.DisplayLinkedList_(myList.get_head_());
  return 0;
}
