#include<iostream>

class HashTable{
public:
    HashTable();
    int Hash(int key);
    void Insert(int key);
    int Search(int key);
    void Remove(int key);
    void ResizeTable();
    ~HashTable();
private:
    int* Hash_table_;
    int capacity_;
    int size_;
    int GetNextIndex(int index);
    double GetLoadFactor();
};

HashTable::HashTable(){
    capacity_=10;
    Hash_table_= new int [capacity_];
    for (int i = 0; i < capacity_; ++i) {
        Hash_table_[i]=-1;
    }
    size_=0;
}

int HashTable::Hash(int key) {
    return key%capacity_;
}

int HashTable::GetNextIndex(int index) {
    return (index+1)%capacity_;
}

double HashTable::GetLoadFactor() {
    return static_cast<double>(size_)/capacity_;
}
void HashTable::Insert(int key) {
    if (GetLoadFactor()>0.75){
        ResizeTable();
    }
    int index= Hash(key);
    int start_index=index;

    while (Hash_table_[index]!=-1){
        if (Hash_table_[index]==key){
            return;
        }

        index= GetNextIndex(index);
        if (index==start_index){
            return;
        }
    }
    Hash_table_[index]=key;
    size_++;
}

int HashTable::Search(int key) {
    int index= Hash(key);
    int start_index=index;
    while (Hash_table_[index]!=-1){
        if (Hash_table_[index]==key){
            return index;
        }
        index= GetNextIndex(index);
        if(index==start_index){
            return -1;
        }
    }
    return -1;
}

void HashTable::Remove(int key) {
    int index= Search(key);
    if (index!=-1){
        Hash_table_[index]=-1;
        size_--;
    }
}
void HashTable::ResizeTable() {
    int new_capacity= capacity_*2;
    int* new_table= new int [new_capacity];
    for (int i = 0; i < new_capacity; ++i) {
        new_table[i]=-1;
    }
    for (int i = 0; i < capacity_; ++i) {
        if (Hash_table_[i]!=-1){
            int key= Hash_table_[i];
            int new_index=key%new_capacity;
            while (new_table[new_index]!= -1){
                new_index= GetNextIndex(new_index);
            }
            new_table[new_index]=key;
        }
    }
    delete [] Hash_table_;
    Hash_table_=new_table;
    capacity_=new_capacity;
}
HashTable::~HashTable() {
    delete[] Hash_table_;
}

int main() {
    HashTable HT;

    char operation;
    int number;

    int queries;
    std::cin >> queries;

    while (queries != 0) {
        std::cin >> operation >> number;

        if (operation == '+') {
            HT.Insert(number);
        } else if (operation == '-') {
            HT.Remove(number);
        } else if (operation == '?') {
            if (HT.Search(number) != -1) {  // Check if the return value is not -1
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
        queries--;
    }

    return 0;
}
