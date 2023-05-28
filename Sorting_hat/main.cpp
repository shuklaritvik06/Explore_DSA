//
// Created by rituparn on 23.05.23.
//


#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class Queue {
private:
    stack<int> element_stack_;
    stack<int> dequeue_stack_;
    stack<int> min_stack_;

public:
    Queue() {}
    ~Queue() {}

    void Enqueue(int x);
    int Dequeue();
    int Front();
    int Size();
    bool IsEmpty();
    void Clear();
    int GetMin();
};

void Queue::Enqueue(int x) {
    element_stack_.push(x);
    if (min_stack_.empty() || x <= min_stack_.top()) {
        min_stack_.push(x);
    }
}

int Queue::Dequeue() {
    if (dequeue_stack_.empty()) {
        if (element_stack_.empty()) {
            throw runtime_error("error");
        } else {
            while (!element_stack_.empty()) {
                dequeue_stack_.push(element_stack_.top());
                element_stack_.pop();
            }
        }
    }
    int x = dequeue_stack_.top();
    dequeue_stack_.pop();

    if (x == min_stack_.top()) {
        min_stack_.pop();
    }
    return x;
}

int Queue::Front() {
    if (dequeue_stack_.empty()) {
        if (element_stack_.empty()) {
            throw runtime_error("Queue is empty");
        } else {
            while (!element_stack_.empty()) {
                dequeue_stack_.push(element_stack_.top());
                element_stack_.pop();
            }
        }
    }
    return dequeue_stack_.top();
}

int Queue::Size() { return element_stack_.size() + dequeue_stack_.size(); }

void Queue::Clear() {
    while (!element_stack_.empty()) {
        element_stack_.pop();
    }
    while (!dequeue_stack_.empty()) {
        dequeue_stack_.pop();
    }
    while (!min_stack_.empty()) {
        min_stack_.pop();
    }
}

int Queue::GetMin() {
    if (min_stack_.empty()) {
        throw runtime_error("Queue is empty");
    }
    return min_stack_.top();
}

int main() {
    Queue q;
    string cmd;
    while (cin >> cmd) {
        try {
            if (cmd == "enqueue") {
                int x;
                cin >> x;
                q.Enqueue(x);
                cout << "ok" << endl;
            } else if (cmd == "dequeue") {
                cout << q.Dequeue() << endl;
            } else if (cmd == "front") {
                cout << q.Front() << endl;
            } else if (cmd == "size") {
                cout << q.Size() << endl;
            } else if (cmd == "clear") {
                q.Clear();
                cout << "ok" << endl;
            } else if (cmd == "min") {
                cout << q.GetMin() << endl;
            } else {
                break;
            }
        } catch (const exception &e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
