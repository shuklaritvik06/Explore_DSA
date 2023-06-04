//
// Created by rituparn on 04.06.23.
//
//
// Created by rituparn on 04.06.23.
//
#include <iostream>
#include <vector>

class UnorderedSet {
private:
    std::vector<std::vector<int>> buckets_;
    std::hash<int> hasher_;

public:
    UnorderedSet(int size) : buckets_(size) {}

    void Insert(int key) {
        int index = GetHashIndex(key);

        for (int element : buckets_[index]) {
            if (element == key) {
                return;
            }
        }

        buckets_[index].push_back(key);
    }

    bool Search(int key) {
        int index = GetHashIndex(key);

        for (int element : buckets_[index]) {
            if (element == key) {
                return true;
            }
        }

        return false;
    }

    void Remove(int key) {
        int index = GetHashIndex(key);
        std::vector<int>& bucket = buckets_[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }

private:
    int GetHashIndex(int key) { return hasher_(key) % buckets_.size(); }
};

int main() {
    UnorderedSet ht(20);

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
            if (ht.Search(number)) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
        queries--;
    }

    return 0;
}
