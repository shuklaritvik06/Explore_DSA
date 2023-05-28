#include <iostream>
#include <stack>
#include <string>

class Queue {
 private:
  std::stack<std::pair<int, int>> in_stack_;
  std::stack<std::pair<int, int>> out_stack_;

 public:
  Queue() {}
  ~Queue() {}

  void Enqueue(int x);
  int Dequeue();
  int Front();
  int Size();
  void Clear();
  int GetMin();
};

void Queue::Enqueue(int x) {
  int current_min = in_stack_.empty() ? x : std::min(x, in_stack_.top().second);
  in_stack_.push(std::make_pair(x, current_min));
}

int Queue::Dequeue() {
  if (out_stack_.empty()) {
    while (!in_stack_.empty()) {
      std::pair<int, int> node = in_stack_.top();
      int current_min = out_stack_.empty()
                            ? node.first
                            : std::min(node.first, out_stack_.top().second);
      out_stack_.push(std::make_pair(node.first, current_min));
      in_stack_.pop();
    }
  }

  if (out_stack_.empty()) {
    return -1;  // Error code for empty queue
  }

  int x = out_stack_.top().first;
  out_stack_.pop();

  return x;
}

int Queue::Front() {
  if (out_stack_.empty()) {
    while (!in_stack_.empty()) {
      std::pair<int, int> node = in_stack_.top();
      int current_min = out_stack_.empty()
                            ? node.first
                            : std::min(node.first, out_stack_.top().second);
      out_stack_.push(std::make_pair(node.first, current_min));
      in_stack_.pop();
    }
  }

  if (out_stack_.empty()) {
    return -1;  // Error code for empty queue
  }

  return out_stack_.top().first;
}

int Queue::Size() { return in_stack_.size() + out_stack_.size(); }

void Queue::Clear() {
  while (!in_stack_.empty()) {
    in_stack_.pop();
  }
  while (!out_stack_.empty()) {
    out_stack_.pop();
  }
}

int Queue::GetMin() {
  if (in_stack_.empty() && out_stack_.empty()) {
    return -1;  // No elements in the queue
  }

  bool has_min = false;
  int min_val;

  if (!in_stack_.empty()) {
    min_val = in_stack_.top().second;
    has_min = true;
  }

  if (!out_stack_.empty()) {
    if (has_min) {
      min_val = std::min(min_val, out_stack_.top().second);
    } else {
      min_val = out_stack_.top().second;
      has_min = true;
    }
  }

  return has_min ? min_val : -1;
}

int main() {
  Queue q;
  std::string cmd;
  int commands;
  std::cin >> commands;
  while (commands != 0) {
    std::cin >> cmd;
    if (cmd == "enqueue") {
      int x;
      std::cin >> x;
      q.Enqueue(x);
      std::cout << "ok\n";
    } else if (cmd == "dequeue") {
      int result = q.Dequeue();
      std::cout << (result == -1 ? "error" : std::to_string(result)) << "\n";
    } else if (cmd == "front") {
      int result = q.Front();
      std::cout << (result == -1 ? "error" : std::to_string(result)) << "\n";
    } else if (cmd == "size") {
      std::cout << q.Size() << "\n";
    } else if (cmd == "clear") {
      q.Clear();
      std::cout << "ok\n";
    } else if (cmd == "min") {
      int result = q.GetMin();
      std::cout << (result == -1 ? "error" : std::to_string(result)) << "\n";
    }
    --commands;
  }
  return 0;
}