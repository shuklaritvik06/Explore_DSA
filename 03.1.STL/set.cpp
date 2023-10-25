#include <iostream>
#include <set>
#include <iterator>

/*
The time complexities for doing various operations on sets are:

Insertion of Elements – O(log N)
Deletion of Elements – O(log N)
 */

int main(){
    std::set<int, std::greater<int> > s1; //by default the set sorts the inserted elements from least to most
    // but we can define our comparison type as the second argument in the set

    s1.insert(40);
    s1.insert(80);
    s1.insert(30);
    s1.insert(20);
    s1.insert(10);

    std::set<int, std::greater<int> >::iterator itr;

    std::cout << "\nThe set s1 is : \n";
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout <<std::endl;
    std::set<int> set2(s1.begin(), s1.end());
    std::cout<<"Removing the element that is less than less than 10\n";
    set2.erase(set2.begin(), set2.find(20)); //erase all the element less than 20
    std::cout << "\nThe set s2 after removal is : \n";
    for (itr = set2.begin(); itr != set2.end(); itr++) {
        std::cout << *itr << "\n";
    }

    //as we didn't define the comparison for the set 2 so it is sorted  from least to most.

    std::cout << "s1.lower_bound(40) : " << *s1.lower_bound(40) <<std::endl;
    std::cout << "s1.upper_bound(40) : " << *s1.upper_bound(40) << std::endl;

    return 0;
}
/*

begin()	Returns an iterator to the first element in the set.

end()	Returns an iterator to the theoretical element that follows the last element in the set.

rbegin()	Returns a reverse iterator pointing to the last element in the container.

rend()	Returns a reverse iterator pointing to the theoretical element right before the first element in the set container.

crbegin()	Returns a constant iterator pointing to the last element in the container.

crend()	Returns a constant iterator pointing to the position just before the first element in the container.

cbegin()	Returns a constant iterator pointing to the first element in the container.

cend()	Returns a constant iterator pointing to the position past the last element in the container.

size()	Returns the number of elements in the set.

max_size()	Returns the maximum number of elements that the set can hold.

empty()	Returns whether the set is empty.

insert(const g) 	Adds a new element ‘g’ to the set.

iterator insert (iterator position, const g)	Adds a new element ‘g’ at the position pointed by the iterator.

erase(iterator position) 	Removes the element at the position pointed by the iterator.

erase(const g)	Removes the value ‘g’ from the set.

clear() 	Removes all the elements from the set.

key_comp() / value_comp()	Returns the object that determines how the elements in the set are ordered (‘<‘ by default).

find(const g)	Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to the end.

count(const g)	Returns 1 or 0 based on whether the element ‘g’ is present in the set or not.

lower_bound(const g)	Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.

upper_bound(const g)	Returns an iterator to the first element that will go after the element ‘g’ in the set.

equal_range()	The function returns an iterator of pairs. (key_comp). The pair refers to the range that includes all the elements in the container which have a key equivalent to k.

emplace()	This function is used to insert a new element into the set container, only if the element to be inserted is unique and does not already exist in the set.

emplace_hint()	Returns an iterator pointing to the position where the insertion is done. If the element passed in the parameter already exists, then it returns an iterator pointing to the position where the existing element is.

swap()	This function is used to exchange the contents of two sets but the sets must be of the same type, although sizes may differ.

operator=	The ‘=’ is an operator in C++ STL that copies (or moves) a set to another set and set::operator= is the corresponding operator function.

get_allocator()	Returns the copy of the allocator object associated with the set.
 */