//
// Created by rituparn on 22.10.23.
//

#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main()
{

    // empty map container
    map<int, int> gquiz1;

    // insert elements in random order
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(4, 20));
    gquiz1.insert(pair<int, int>(5, 50));  //can actually insert elements in the map using the pair
    gquiz1.insert(pair<int, int>(6, 50));

    gquiz1[7]=10;	 // another way of inserting a value in a map


    // printing map gquiz1
    map<int, int>::iterator itr;
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;

    // assigning the elements from gquiz1 to gquiz2
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());

    // print all elements of the map gquiz2
    cout << "\nThe map gquiz2 after"
         << " assign from gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;

    // remove all elements up to
    // element with key=3 in gquiz2
    cout << "\ngquiz2 after removal of"
            " elements less than key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }

    // remove all elements with key = 4
    int num;
    num = gquiz2.erase(4);
    cout << "\ngquiz2.erase(4) : ";
    cout << num << " removed \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }

    cout << endl;

    // lower bound and upper bound for map gquiz1 key = 5
    cout << "gquiz1.lower_bound(5) : "
         << "\tKEY = ";
    cout << gquiz1.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second
         << endl;
    cout << "gquiz1.upper_bound(5) : "
         << "\tKEY = ";
    cout << gquiz1.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second
         << endl;

    return 0;
}




















/*

Some basic functions associated with Map:

begin() – Returns an iterator to the first element in the map.

end() – Returns an iterator to the theoretical element that follows the last element in the map.

size() – Returns the number of elements in the map.

max_size() – Returns the maximum number of elements that the map can hold.

empty() – Returns whether the map is empty.

pair insert(keyvalue, mapvalue) – Adds a new element to the map.

erase(iterator position) – Removes the element at the position pointed by the iterator.

erase(const g)– Removes the key-value ‘g’ from the map.

clear() – Removes all the elements from the map.

map::insert()
Insert elements with a particular key in the map container –> O(log n)

map:: count()
Returns the number of matches to element with key-value ‘g’ in the map. –> O(log n)

map equal_range()
Returns an iterator of pairs. The pair refers to the bounds of a range that includes all the elements in the container which have a key equivalent to k.

map erase()
Used to erase elements from the container –> O(log n)

 map::at() and map::swap()
at() function is used to return the reference to the element associated with the key k.
 swap() function is used to exchange the contents of two maps but the maps must be of the same type, although sizes may differ.



 */