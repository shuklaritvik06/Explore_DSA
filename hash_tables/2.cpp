//
// Created by rituparn on 01.06.23.
//

#include <iostream>
#include <vector>

class HashTable {
public:
    HashTable();
    int Hash(int key);
    void Insert(int key);
    int Search(int key);
    void Remove(int key);
    void ResizeTable();
    ~HashTable();

private:
    std::vector<int> Hash_table_;
    int capacity_;
    int size_;
    int GetNextIndex(int index);
    double GetLoadFactor();
};

HashTable::HashTable() {
    capacity_ = 16;  // Use a power of 2 as the initial capacity
    Hash_table_.resize(capacity_, -1);
    size_ = 0;
}

int HashTable::Hash(int key) { return key & (capacity_ - 1); }

int HashTable::GetNextIndex(int index) {
    return (index + 1) & (capacity_ - 1);  // Use bitwise AND instead of modulo
}

double HashTable::GetLoadFactor() {
    return static_cast<double>(size_) / capacity_;
}

void HashTable::Insert(int key) {
    if (GetLoadFactor() > 0.75) {
        ResizeTable();
    }
    int index = Hash(key);
    int start_index = index;

    while (Hash_table_[index] != -1) {
        if (Hash_table_[index] == key) {
            return;
        }

        index = GetNextIndex(index);
        if (index == start_index) {
            return;
        }
    }
    Hash_table_[index] = key;
    size_++;
}

int HashTable::Search(int key) {
    int index = Hash(key);
    int start_index = index;
    while (Hash_table_[index] != -1) {
        if (Hash_table_[index] == key) {
            return index;
        }
        index = GetNextIndex(index);
        if (index == start_index) {
            break;
        }
    }
    return -1;
}

void HashTable::Remove(int key) {
    int index = Search(key);
    if (index != -1) {
        Hash_table_[index] = -1;
        size_--;
    }
}

void HashTable::ResizeTable() {
    int new_capacity = capacity_ * 2;
    std::vector<int> new_table(new_capacity, -1);
    for (int i = 0; i < capacity_; ++i) {
        if (Hash_table_[i] != -1) {
            int key = Hash_table_[i];
            int new_index = Hash(key);
            while (new_table[new_index] != -1) {
                new_index = GetNextIndex(new_index);
            }
            new_table[new_index] = key;
        }
    }
    Hash_table_ = new_table;
    capacity_ = new_capacity;
}

HashTable::~HashTable() {}

int main() {
    HashTable ht;

    char operation;
    int number;

    int queries;
    std::cin >> queries;

    while (queries != 0) {
        std::cin >> operation >> number;

        if (operation == '+') {
            ht.Insert(number);
        } else if (operation == '-') {
            ht.Remove(number);
        } else if (operation == '?') {
            if (ht.Search(number) != -1) {
                std::cout << "YES"<<std::endl;
            } else {
                std::cout << "NO"<<std::endl;
            }
        }
        queries--;
    }

    return 0;
}
