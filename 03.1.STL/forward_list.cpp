//
// Created by rituparn on 22.10.23.
//


/*
 * assign(): This function is used to assign values to the forward list, its other variant is used to assign repeated elements and using the values of another list.
 *  push_front(): This function is used to insert the element at the first position on forward list. The value from this function is copied to the space before first element in the container. The size of forward list increases by 1.
 *  emplace_front(): This function is similar to the previous function but in this no copying operation occurs, the element is created directly at the memory before the first element of the forward list.
 *  pop_front(): This function is used to delete the first element of the list.
 *   insert_after(): This function gives us a choice to insert elements at any position in forward list. The arguments in this function are copied at the desired position.
* emplace_after(): This function also does the same operation as the above function but the elements are directly made without any copy operation.
 * erase_after(): This function is used to erase elements from a particular position in the forward list. There are two variants of ‘erase after’ function.
 * clear(): This function deletes all the elements from the list.
 * splice_after(): This function transfers elements from one forward list to other.
 */

//So basically flist or forward list is the singly linked list


#include <forward_list>
#include <iostream>
using namespace std;

// Driver Code
int main()
{
    // Initializing forward list
    forward_list<int> flist1 = { 10, 20, 30 };

    // Initializing second list
    forward_list<int> flist2 = { 40, 50, 60 };

    // Shifting elements from first to second
    // forward list after 1st position
    flist2.splice_after(flist2.begin(), flist1);

    // Displaying the forward list
    cout << "The forward list after splice_after operation "
            ": ";
    for (int& c : flist2)
        cout << c << " ";
    cout << endl;

    return 0;
}
