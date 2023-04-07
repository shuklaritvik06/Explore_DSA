#include <iostream>
#include <string>

struct Node {
  char data;
  Node *next;
};

class List {
private:
  Node *head;

public:
  explicit List(std::string);
  ~List(); // destructor added
  void DisplayLinkedList();
  void ReverseLinkedList();
};

List::List(std::string str) {
  head = nullptr;
  Node *tail = nullptr;
  for (int i = 0; i < str.length(); i++) {
    Node *new_node = new Node;
    new_node->data = str[i];
    new_node->next = nullptr;
    if (head == nullptr) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }
}

// destructor implementation
List::~List() {
  Node *current = head;
  while (current != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
  }
}

void List::DisplayLinkedList() {
  Node *ptr = head;
  while (ptr != nullptr) {
    std::cout << ptr->data;
    ptr = ptr->next;
  }
}

void List::ReverseLinkedList() {
  Node *prev = nullptr;
  Node *current = head;
  Node *next = nullptr;
  while (current != nullptr) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

int main() {
  std::string str;
  std::getline(std::cin, str);
  List myList{str};
  myList.ReverseLinkedList();
  myList.DisplayLinkedList();
  return 0;
}