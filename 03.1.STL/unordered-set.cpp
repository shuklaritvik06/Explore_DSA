//
// Created by rituparn on 22.10.23.
//

/*
 An unordered_set is an unordered associative container implemented using a hash table where keys are hashed into
 indices of a hash table so that the insertion is always randomized. All operations on the unordered_set take constant
 time O(1) on an average which can go up to linear time O(n) in the worst case which depends on the internally used hash
 function, but practically they perform very well and generally provide a constant time lookup operation.

The unordered_set can contain a key of any type – predefined or user-defined data structure but all the keys must be
 unique. It is defined inside <unordered_set> header file as std::unordered_set class.

Syntax:

std::unordered_set<data_type> name;
In std::unordered_set, many functions are defined among which the most used functions are:

The size() and empty() for capacity.
The find() for searching a key.
The insert () and erase() for modification.
 */


// C++ program to demonstrate various function of
// unordered_set
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // declaring set for storing string data-type
    unordered_set<string> stringSet;

    // inserting various string, same string will be stored
    // once in set

    stringSet.insert("code");
    stringSet.insert("in");
    stringSet.insert("c++");
    stringSet.insert("is");
    stringSet.insert("fast");

    string key = "slow";

    // find returns end iterator if key is not found,
    // else it returns iterator to that key

    if (stringSet.find(key) == stringSet.end())
        cout << key << " not found" << endl << endl;
    else
        cout << "Found " << key << endl << endl;

    key = "c++";
    if (stringSet.find(key) == stringSet.end())
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;

    // now iterating over whole set and printing its
    // content
    cout << "\nAll elements : ";
    unordered_set<string>::iterator itr;
    for (itr = stringSet.begin(); itr != stringSet.end();
         itr++)
        cout << (*itr) << endl;
}
/*
*********************** SET VS UNORDERED SET ***********************

a set is the ordered sequence of the unique keys

in unordered_set the key can be stored in any order

SET uses balancing tree structure

Unordered tree is implemented as the hash-table so no need to worry about the ordering

The time complexity of the set is given as O(log n)

The time complexity of the basic set operation is O(1)

*/